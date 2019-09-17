#include "gtest/gtest.h"
#include <utility>
template <typename T, typename = void> struct is_iterable : std::false_type {};
template <typename T>
struct is_iterable<T, std::void_t<decltype(std::declval<T>().begin()),
                                  decltype(std::declval<T>().end())>>
    : std::true_type {};

TEST(DECLVAL, DECLVAL) {
  bool re = is_iterable<std::vector<double>>::value; // prints 1
  ASSERT_TRUE(re);
}
