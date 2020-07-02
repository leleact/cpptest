#include <gtest/gtest.h>

TEST(operator, self_increase) {
  const char *s1 = "ab";
  const char *s2 = "ac";
  ASSERT_TRUE(*s1++ == *s2++);
  std::cout << *s1 << "..." << *s2 << std::endl;
}
