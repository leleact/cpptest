#include <gtest/gtest.h>

struct A {

  std::string operator()(const std::string &__str) { return __str; }
};

TEST(FUNCTION, OPERATOR) {
  std::string _s{"111"};
  std::string _r = A{}(_s);
  ASSERT_EQ("111", _r);
}
