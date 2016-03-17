#ifndef _UNIT_TEST_H
#define _UNIT_TEST_H

#include <iostream>
#include <list>
#include <memory>
#include "TestCase.h"

class UnitTest {
public:
    static std::list< std::shared_ptr<TestProc> > &getList();
    static std::list< std::shared_ptr<TestProc> > m_TestProcs;
    void run();
} UnitTest_Instance;

std::list< std::shared_ptr<TestProc> > UnitTest::m_TestProcs;

std::list< std::shared_ptr<TestProc> > &UnitTest::getList() {
    return m_TestProcs;
}

void UnitTest::run() {
    std::cout << "[" << __FILE__ << ":" << __LINE__ << "]" << m_TestProcs.size() << std::endl;
    std::list< std::shared_ptr<TestProc> >::iterator it = m_TestProcs.begin();
    for (; it != m_TestProcs.end(); it++ ) {
        (*it)->run();
    }
}

#endif
