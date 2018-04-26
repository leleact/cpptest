#include "gtest/gtest.h"
#include <thread>
#include <chrono>
#include <vector>

namespace cpptests_pthread_cond_awakeup {

class base_waiter {
  protected:
      base_waiter() {
          std::clog << std::this_thread::get_id()  <<" - (" << __FILE__ << ":"<< __LINE__ << ")[" << __PRETTY_FUNCTION__ << "] - {}" << std::endl;
          pthread_mutex_init(&_mutex, NULL);
          pthread_cond_init(&_cond, NULL);
      }

      ~base_waiter() {
          std::clog << std::this_thread::get_id()  <<" - (" << __FILE__ << ":"<< __LINE__ << ")[" << __PRETTY_FUNCTION__ << "] - {}" << std::endl;
          pthread_mutex_destroy(&_mutex);
          pthread_cond_destroy(&_cond);
      }

      pthread_mutex_t _mutex;
      pthread_cond_t _cond;
};


class waiter : private base_waiter {
  public:
      waiter() : _signaled(false) {}

      void wait() {
          pthread_mutex_lock(&_mutex);
          while(!_signaled) {
              pthread_cond_wait(&_cond, &_mutex);
          }
          //std::this_thread::sleep_for(std::chrono::seconds(1));
          pthread_mutex_unlock(&_mutex);
      }

      /**
       * 惊鸿效应, 会唤醒多个线程
       */
      void signal() {
          pthread_mutex_lock(&_mutex);
          _signaled = true; 
          pthread_mutex_unlock(&_mutex);
          pthread_cond_signal(&_cond);
      }

      /**
       * pthread_cond_broadcast 触发一次，会唤醒所有线程
       * 同一时间只有一个线程能获取到mutex的锁
       */
      void broadcast() {
          pthread_mutex_lock(&_mutex);
          _signaled = true; 
          pthread_mutex_unlock(&_mutex);
          pthread_cond_broadcast(&_cond);
      }


private:
      bool _signaled;
};

TEST(pthread_cond, pthread_cond_broadcast) {

    constexpr const int pthread_wait_num = 10;

    waiter w = waiter();

    std::vector<std::thread> vec;
    for (int i = 0; i < pthread_wait_num; i++) {
        vec.emplace_back(std::thread([&](){
          w.wait(); 
          std::clog << std::this_thread::get_id()  <<" - (" << __FILE__ << ":"<< __LINE__ << ")[" << __PRETTY_FUNCTION__ << "] - {awake}" << std::endl;
          }));
    }

    std::thread s = std::thread([&](){
           w.broadcast(); 
            });

    for (std::vector<std::thread>::iterator it = vec.begin(); it != vec.cend(); it++) {
        it->join();
    }
    s.join();

}

TEST(pthread_cond, pthread_cond_signal) {

    constexpr const int pthread_wait_num = 10;

    waiter w = waiter();

    std::vector<std::thread> vec;
    for (int i = 0; i < pthread_wait_num; i++) {
        vec.emplace_back(std::thread([&](){
          w.wait(); 
          std::clog << std::this_thread::get_id()  <<" - (" << __FILE__ << ":"<< __LINE__ << ")[" << __PRETTY_FUNCTION__ << "] - {awake}" << std::endl;
          }));
    }

    std::thread s = std::thread([&](){
           w.signal(); 
            });

    w.broadcast(); // 关闭线程

    for (std::vector<std::thread>::iterator it = vec.begin(); it != vec.cend(); it++) {
        it->join();
    }
    s.join();
}
}
