#ifndef _SINGLETON_H
#define _SINGLETON_H

#if __cplusplus < 201103L
#include <pthread.h>
#endif

template<typename T>
class Singleton {
    public:
        static Singleton &GetInstance () { 
#if __cplusplus >= 201103L
            static Singleton instance;
#else
            pthread_mutex_lock(&m_Mutex);
            static Singleton instance;
            pthread_mutex_unlock(&m_Mutex);
#endif
            return instance; 
        }
    private:
        Singleton () {};
        Singleton ( const Singleton &) {}
        Singleton &operator = ( const Singleton &) {}
#if __cplusplus >= 201103L
        Singleton ( const Singleton &&) = default;
        Singleton &operator = ( const Singleton &&) = default;
#else
        static pthread_mutex_t m_Mutex;
#endif
};

#endif
