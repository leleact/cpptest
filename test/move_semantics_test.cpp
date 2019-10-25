#include "gtest/gtest.h"

#define MARK                                                                   \
  do {                                                                         \
    std::cout << "[" << __FILE__ << ":" << __LINE__ << "]("                    \
              << __PRETTY_FUNCTION__ << ")" << std::endl;                      \
  } while (0)

// class X in namespace x1 with no move semantics
namespace x1 {

class X {
public:
  X() { MARK; }

  X(const X &x) { MARK; }

  X &operator=(const X &x) {
    MARK;
    return *this;
  }

private:
  X(X &&) = delete;
  X &operator=(X &&) = delete;
};

} // namespace x1

// class X in namespace x2 with move semantics
namespace x2 {

class X {

public:
  X() { MARK; }

  X(const X &x) { MARK; }

  X(X &&x) { MARK; }
  X &operator=(const X &x) {
    MARK;
    return *this;
  }

  X &operator=(X &&x) {
    MARK;
    return *this;
  }
};

} // namespace x2

namespace x3 {
x1::X f() {
  MARK;
  x1::X x_1{};
  return x_1;
}

x2::X g() {
  MARK;
  return x2::X();
}

}; // namespace x3

TEST(move, right_reference) {
  x2::X xx = []() { return x2::X{}; }();
  x2::X x2;
  x2 = x2::X{};
}

TEST(move, rvo) {
  // x1::X &x_11 = x3::f(); // need move copy
  const x1::X &x_1 = x3::f();
  x2::X x_2 = x3::g();
}
