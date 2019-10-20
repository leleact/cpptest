#include <gtest/gtest.h>

TEST(std_map, emplace) {

  struct X {
    std::string x;
    // X(std::initializer_list<std::string> list) { x = *list.begin(); }
  };

  struct Y {
    long x;
  };

  std::map<std::string, X> m1;
  std::map<std::string, Y> m2;

  m1.emplace("k1", X{"x"});
  m2.emplace("k2", Y{1});

  ASSERT_EQ(1, m1.size());
  ASSERT_EQ(1, m2.size());
}
