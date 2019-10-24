#include <gtest/gtest.h>

template <typename T> class base {
public:
  const int findById(const std::string &id) {
    T *ptr = static_cast<T *>(this);
    return ptr->findById_(id);
  }
};

class derived : public base<derived> {
public:
  const int findById_(const std::string &id) { return 1; }
};

TEST(crtp, func) {
  base<derived> *ptr = new derived();
  int rc = ptr->findById("1");
  ASSERT_EQ(1, rc);
}
