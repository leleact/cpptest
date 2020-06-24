#include <gtest/gtest.h>

TEST(gtest, statement) {

  // Macro处理参数时会将逗号(,)作为Macro的参数分割符，造成进入Macro的参数被分割,ASSERT_NO_THROW的statement不被识别
  // 因此解决方案可以使用lambda expression代替statement
  // <a
  // href="https://stackoverflow.com/questions/41681243/compilation-error-using-googletests-expect-no-throw-with-stdarray">see
  // here</a>
  ASSERT_NO_THROW([] {}());
}