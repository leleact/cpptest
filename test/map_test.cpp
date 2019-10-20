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

TEST(map, order) {
  using c_it = std::map<int, int>::const_iterator;
  std::vector<int> asserts;
  std::map<int, int> map;
  map.emplace(3, 3);
  map.emplace(1, 1);
  map.emplace(2, 2);

  for (c_it it = map.cbegin(); it != map.cend(); ++it) {
    asserts.push_back(it->first);
  }
  ASSERT_EQ(1, asserts[0]);
  ASSERT_EQ(2, asserts[1]);
  ASSERT_EQ(3, asserts[2]);
}
