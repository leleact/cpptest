#ifndef _TEST_PROC_H
#define _TEST_PROC_H

#include <iostream>
#include <list>
#include "UnitTest.h"

#define TestCase(name)                                                     \
    class TestCase_##name : public TestProc {                              \
    public:                                                                \
        TestCase_##name( std::list<std::shared_ptr<TestProc>>& list ) {    \
                      list.push_back(std::shared_ptr<TestProc>(this));     \
                  }                                                        \
        virtual ~TestCase_##name() {}                                      \
        virtual void run() const override;                                 \
    } TestCase_##name##_Instance( UnitTest::getList() );                   \
    void TestCase_##name::run() const

class TestProc {
    public:
        virtual ~TestProc() {}
        virtual void run() const {
            std::cout << "[" << __FILE__ << ":" << __LINE__ << "](" << __func__ << ")" << std::endl;
        }
};

#endif
