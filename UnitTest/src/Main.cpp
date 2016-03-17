#include <iostream>
#include "UnitTest.h"
#include "TestCase.h"

TestCase(is_equal) {
    std::cout << "true" << std::endl;
}

int main(int argc, char *argv[]) {
    UnitTest ut;
    ut.run();
	return 0;
}
