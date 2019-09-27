#include "gtest/gtest.h"
#include <gtest/gtest_pred_impl.h>
#include <random>

TEST(RANDOM_DISTRIBUTE, UNIFORM_INT) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(1, 6);
  ASSERT_LE(dis(gen), 6);
}
