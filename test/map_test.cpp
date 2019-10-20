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

TEST(map, square_brackets) {
  {
    std::map<std::string, long> map;
    long l = map[std::string("a")];
    ASSERT_EQ(0, l);
    ASSERT_EQ(1, map.size());
  }
  {
    struct X {
      std::string name;
      X() {}
      X(const std::string &n) : name(n){};
      X(const X &x) { name = x.name; }
      X(X &&x) { name = std::move(x.name); }
    };

    std::map<std::string, X> map;
    X x = map[std::string("a")];
  }
}
