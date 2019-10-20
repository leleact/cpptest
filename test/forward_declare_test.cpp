#include <gtest/gtest.h>

TEST(forward_declear, struct_forward_delare) {

  struct A;

  // only reference or pointer
  struct B1 {
    A &a;
  };

  struct B2 {
    A *pa;
  };

  struct A {
    long l;
  };

  A a{10};
  B1 b1 = {a};
  B2 b2 = {new A{20}};

  ASSERT_EQ(10, b1.a.l);
  ASSERT_EQ(20, b2.pa->l);
}
