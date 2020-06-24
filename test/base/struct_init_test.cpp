#include <gtest/gtest.h>

extern "C" {
typedef struct {
  int id;
  char *name;
} Employee;

TEST(struct, init) {
  ASSERT_NO_THROW(
      ([] { Employee emp = {.id = 0, .name = (char *)"Alice"}; }()));
}
}
