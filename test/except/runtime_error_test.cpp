#include <gtest/gtest.h>

TEST(except, runtime_error) {
  ASSERT_THROW([]() { throw std::runtime_error{"xxxxxx"}; }(),
               std::runtime_error);
}
