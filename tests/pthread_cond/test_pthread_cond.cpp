#include "gtest/gtest.h"
#include <pthread.h>

namespace cpptests_pthread_cond {

struct meta_data {

  bool activation;

  long loop_count;

  pthread_mutex_t mutex  ;

  pthread_cond_t cond  ;

};

void* thread_function(void* pargs) {
    std::clog << pthread_self()  <<" - (" << __FILE__ << ":"<< __LINE__ << ")[" << __PRETTY_FUNCTION__ << "]" << std::endl;
    struct meta_data* pdata = (struct meta_data*)pargs;
    while(true) {
        pthread_mutex_lock(&pdata->mutex);
        while(!pdata->activation) { // mutex is used to protected cond
            pthread_cond_wait(&pdata->cond, &pdata->mutex);
        }
        if (pdata->loop_count > 0) {
            pdata->loop_count--; /* do what you want */
            pdata->activation = false;
        } else {
            pthread_mutex_unlock(&pdata->mutex);
            break;
        }
        pthread_mutex_unlock(&pdata->mutex);
    }
    return pargs;
}

void* thread_activate(void* pargs) {
    std::clog << pthread_self()  <<" - (" << __FILE__ << ":"<< __LINE__ << ")[" << __PRETTY_FUNCTION__ << "]" << std::endl;
    struct meta_data* pdata = (struct meta_data*)pargs;
    while(true) {
         pthread_mutex_lock(&pdata->mutex);
         if (pdata->loop_count <= 0) {
             pdata->activation = true;
             pthread_mutex_unlock(&pdata->mutex);
             pthread_cond_broadcast(&pdata->cond);
             break;
         }
         if (pdata->loop_count > 0) {
            pdata->activation = true;
         }
         pthread_mutex_unlock(&pdata->mutex);
         pthread_cond_signal(&pdata->cond);
    }
    return pargs;
}

TEST(pthread_cond, phread_cond) {

    const int pthread_num = 10;
    const int pthread_activate_num = 10;
    pthread_t thread_array[pthread_num];
    pthread_t thread_activate_array[pthread_activate_num];

    struct meta_data test_data;
    test_data.loop_count = 1000;
    test_data.activation = false;
    pthread_mutex_init(&test_data.mutex, NULL);
    pthread_cond_init(&test_data.cond, NULL);

    for (int i = 0; i < pthread_num; i++) {
        pthread_create(&thread_array[i], NULL, thread_function, &test_data);
    }
    for (int i = 0; i < pthread_activate_num; i++) {
        pthread_create(&thread_activate_array[i], NULL, thread_activate, &test_data);
    }


    for (int i = 0; i < pthread_num; i++) {
        pthread_join(thread_array[i], NULL);
    }

    for (int i = 0; i < pthread_activate_num; i++) {
        pthread_join(thread_activate_array[i], NULL);
    }

    pthread_mutex_destroy(&test_data.mutex);
    pthread_cond_destroy(&test_data.cond);
    EXPECT_EQ(0, test_data.loop_count);
}
}
