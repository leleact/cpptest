#include <gtest/gtest.h>
#include <stdexcept>
class my_ex : public std::runtime_error {
public:
  my_ex(const std::string &__what) : std::runtime_error(__what) {}
  my_ex(const char *__what) : std::runtime_error(__what) {}
};

struct base {
  base(bool thr) {
    if (thr) {
      throw my_ex{std::string{"--15"}};
    }
  }
};

struct derived : public base {

  derived() try : base(true) {
  } catch (...) {
  }
};

TEST(exception, throw_ex) {
  ASSERT_THROW(base{true}, my_ex);
  ASSERT_NO_THROW(base{false});
}

TEST(exception, derived_ex) { ASSERT_THROW(derived{}, my_ex); }
