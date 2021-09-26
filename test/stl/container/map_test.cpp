#include <gtest/gtest.h>
#include <map>

TEST(map, emplace) {
  std::map<std::string, int> map;
  map.emplace("a", 1);
  map.emplace("b", 1);
  map.emplace("c", 1);
  ASSERT_EQ(3, map.size());
}