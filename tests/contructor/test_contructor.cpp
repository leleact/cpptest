#include <gtest/gtest.h>
#include <iostream>

namespace cpptests_test_contructor {

class contructor {
public:
    contructor() { indicator = __PRETTY_FUNCTION__; }

    contructor(const contructor&) { indicator = __PRETTY_FUNCTION__; }

    contructor(contructor&&) { indicator = __PRETTY_FUNCTION__; }

    contructor& operator=(const contructor&) {
        indicator = __PRETTY_FUNCTION__;
        return *this;
    }

    contructor& operator=(contructor&&) {
        indicator = __PRETTY_FUNCTION__;
        return *this;
    }

    const char* what_indicator() const { return indicator.c_str(); }

private:
    std::string indicator;
};

TEST(constructor, which_contrutor_test) {
    contructor c{};

    std::clog << c.what_indicator() << std::endl;
}

}  // namespace cpptests_test_contructor
