#ifndef _TEST_PROC_H
#define _TEST_PROC_H

#include <iostream>
#include <list>
#include "UnitTest.h"

#define TestCase(name)                                                     \
    class TestCase_##name : public TestProc {                              \
    public:                                                                \
        TestCase_##name() {}                                               \
        virtual ~TestCase_##name() { std::cout << "~" << std::endl;}       \
        virtual void run() const override;                                 \
    } TestCase_##name##_Instance;                                          \
    void TestCase_##name::run() const




class TestProc : public std::enable_shared_from_this<TestProc> {
    public:
        virtual ~TestProc() {}
        virtual void run() const {
            std::cout << "[" << __FILE__ << ":" << __LINE__ << "](" << __func__ << ")" << std::endl;
        }
};



#endif
