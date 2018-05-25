#include <gtest/gtest.h>
#include <algorithm>
#include <iostream>
#include <vector>

TEST(stl_test, std_copy_test) {
    std::vector<int> from = {1, 3, 5, 7, 9};

    std::vector<int> to;

    std::copy(from.begin(), from.end(), std::back_inserter(to));

    EXPECT_EQ(5, to.size());
}
