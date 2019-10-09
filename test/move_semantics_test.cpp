#include "gtest/gtest.h"

// class X in namespace x1 with no move semantics
namespace x1 {

class X {
public:
  X() { std::cout << __PRETTY_FUNCTION__ << std::endl; }

  X(const X &x) { std::cout << __PRETTY_FUNCTION__ << std::endl; }

  X &operator=(const X &x) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    return *this;
  }
};

} // namespace x1

// class X in namespace x2 with move semantics
namespace x2 {

class X {

public:
  X() { std::cout << __PRETTY_FUNCTION__ << std::endl; }

  X(const X &x) { std::cout << __PRETTY_FUNCTION__ << std::endl; }

  X(X &&x) { std::cout << __PRETTY_FUNCTION__ << std::endl; }

  X &operator=(const X &x) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    return *this;
  }

  X &operator=(X &&x) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    return *this;
  }
};

} // namespace x2

TEST(move, right_reference) {
  x2::X xx = []() { return x2::X{}; }();
  x2::X x2;
  x2 = x2::X{};
}
