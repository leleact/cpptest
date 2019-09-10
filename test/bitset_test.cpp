#include "gtest/gtest.h"
#include <bitset>

TEST(BIT_SET, INT_TO_BIT_SET) {
  std::bitset<8> c(-140);
  std::cout << c.to_string() << std::endl;
  EXPECT_EQ("01110100", c.to_string());
}
