#include "gtest/gtest.h"
#include <utility>
template <typename T, typename = void> struct is_iterable : std::false_type {};
template <typename T>
struct is_iterable<
    T,
#if __cplusplus >= 201703L || !defined(__STRICT_ANSI__) // c++17 or gnu++11
#ifdef __cpp_lib_void_t
    std::void_t
#else
    std::__void_t
#endif
#else
    std::__void_t
#endif
    <decltype(std::declval<T>().begin()), decltype(std::declval<T>().end())>>
    : std::true_type {
};

TEST(DECLVAL, DECLVAL) {
  bool re = is_iterable<std::vector<double>>::value; // prints 1
  ASSERT_TRUE(re);
}
