#include "gtest_trail.h"

TEST(EqualTest, BaseEqual) {
    v1::base b;
    v1::base d;
    EXPECT_EQ(b, d);
}