#include "gtest/gtest.h"

// Template template arguments example
// ref: https://en.cppreference.com/w/cpp/language/template_parameters
template <typename T> struct Data {
  T left;
  T right;
};

template <typename T> T add(const Data<T> &data) {
  return data.left + data.right;
}

template <template <typename> class Data, typename T>
T add(const Data<T> data) {
  return data.left + data.right;
}

TEST(Template, Argument) {
  ASSERT_EQ(3, (add<Data, int>({1, 2})));
  ASSERT_EQ(3, add<int>({1, 2}));
}
