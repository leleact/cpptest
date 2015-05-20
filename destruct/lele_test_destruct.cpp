#include <iostream>
struct Base {
  void f() {
    std::cout << "Base f()" << std::endl; 
  }

  virtual void g() {
    std::cout << "Base g()" << std::endl; 
  }
};

struct Deveried : public Base {

};

int main() {
  Deveried d;
  d.f();
  d.g();

  return 0;
}
