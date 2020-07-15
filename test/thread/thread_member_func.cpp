#include <gtest/gtest.h>
#include <thread>

class Callable {

public:
  virtual int operator()(int a) {
    std::cout << "a=" << a << std::endl;
    return 0;
  }

  virtual ~Callable() {}
};

TEST(thread, virtual_member) {
  Callable c;
  std::thread t(&Callable::operator(), &c, 1);
  t.join();
}
