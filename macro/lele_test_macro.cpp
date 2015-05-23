#include <iostream>
#define MAX(x, y) x > y ? x : y //如果没有加上括号 宏中没有办法做参数运算, C99可以支持inline函数
int main() {
  int a = 5;
  int b = 10;
  int c = MAX( a + 1, b + 1);
  std::cout << c << std::endl;

  return 0;
}
