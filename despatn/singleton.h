#include <iostream>
#include <memory>
#ifndef _SINGLETON_H
#define _SINGLETON_H
class Singleton {
private:
    Singleton();
    static Singleton ms_instance;
public:
    static std::shared_ptr<Singleton> Getinstance();
};
#endif
