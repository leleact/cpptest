#include "gtest/gtest.h"

TEST(FirstTest, Item1) {
  std::printf("running test");
  EXPECT_EQ(100, 100);
}
