#include "gtest/gtest.h"

struct B {
  int ib;
  virtual void f() {}
};

struct B1 : virtual public B {
  int ib1;
  virtual void f() override {}
};

struct B2 : virtual public B {
  int ib2;
  virtual void f() override {}
};

struct D : public B1, public B2 {
  int id;
  virtual void f() override {}
};

TEST(Object, Model) {
  D *d = new D{};
  B1 *b1 = (B1 *)d;
  B2 *b2 = (B2 *)d;
  B *b = (B *)d;
  [] {}();
}