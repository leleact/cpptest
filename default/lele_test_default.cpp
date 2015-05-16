#include <iostream>
#include <memory>
class X {
public:
  X() = default;
  X(int a) : i(a) {}
  int  Show() {
    std::cout << i << std::endl; 
    return i;
  }
private:
  int i;
};

int main(int argc, char **argv) {
//X x1; = default 不能直接用来构造对象, 但是当需要用到默认构造函数时, 居然可以用到 eg:make_shared
  X x(3);
  std::shared_ptr<X> ptr = std::make_shared<X>();
  std::cout << ptr->Show() << std::endl;
  return 0;
}
