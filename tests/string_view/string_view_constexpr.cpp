#if 0
/**
 * string_view 似乎在travis上的g++-7中有bug,无法编译通过
 *
 */
#if __cplusplus >= 201703L
#include "gtest/gtest.h"
#include <iostream>
#include <array>
#include <string_view>

template <typename ENV>
struct Context {
    constexpr static const std::string_view value = ENV::value;
};

struct DEV {
    constexpr static const std::string_view value = "dev";
};

struct SIT {
    constexpr static const std::string_view value = "sit";
};

struct UAT {
    constexpr static const std::string_view value = "uat";
};

TEST(test_string_view, string_view_constexpr) {
    EXPECT_EQ("uat", Context<UAT>::value);
}

#endif
#endif
