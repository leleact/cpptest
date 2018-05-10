#include <gtest/gtest.h>
#include <bitset>
#include <sstream>

namespace cpptest_bitset_test {

TEST(bitset, use_test) {
    std::bitset<32> negative = -1;
    EXPECT_EQ("11111111111111111111111111111111",
              static_cast<std::ostringstream&>(std::ostringstream() << negative)
                  .str());
}
}  // namespace cpptest_bitset_test
