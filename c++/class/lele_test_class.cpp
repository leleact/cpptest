#include <iostream>
struct X {
  X() = default;
  X(const X &) = default;
  X(X &&) = default;
  X &operator=(const X &) = default;
  X &operator=(X &&) = default;
  virtual ~X() = default;
};

struct Y : private X {};

class Base {};

class Deried : public Base {
public:
  Deried(const Deried &d) : Base(d) {}
  Deried(Deried &&d) : Base(std::move(d)) {}
  Deried &operator=(const Deried &d) {
    Base::operator=(d);
    return *this;
  }
  Deried &operator=(Deried && d) {
    Base::operator=(std::move(d)); 
    return *this;
  }
private:
};

int main() {
  Y y;
  //Base b(); // 被识别为函数声明
}
