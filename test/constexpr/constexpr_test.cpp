#include <gtest/gtest.h>

constexpr int add(int a, int b) { return a + b; }

int minus(int a, int b) { return a - b; }

int x = 100;

class A {

public:
  constexpr A() {}

  constexpr int f(int i) { return i + 1; }

  int g(int i) { return i + 2; }

  constexpr int f1(int i) {
    // Non-constexpr function 'minus' cannot be used in a constant expression
    // return minus(i, 1);
    // or
    // const int c = minus(i, 1);
    // return c;

    //
    int c = add(i, 10);
    return c;
  }
};

TEST(CONSTEXPR, FUNCTION) {
  int c = add(1, 2);
  ASSERT_EQ(3, c);
}

TEST(CONSTEXPR, MEMBER_FUNCTION) {
  A a;
  ASSERT_EQ(11, a.f(10));
  ASSERT_EQ(24, a.g(22));
}
