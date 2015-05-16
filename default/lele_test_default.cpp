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
  X x(3);
  std::shared_ptr<X> ptr = std::make_shared<X>();
  std::cout << ptr->Show() << std::endl;
  return 0;
}
