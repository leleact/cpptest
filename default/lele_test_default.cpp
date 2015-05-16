#include <iostream>
class X {
public:
  X() = default;
  //X(int a = 0) : i(a) {}
private:
  int i;
};
int main(int argc, char **argv) {
  X x; 
//  X x();
  //X x1(4);
  return 0;
}
