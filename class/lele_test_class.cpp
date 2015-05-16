#include <iostream>
class X {
public:
  X(int i = 0) : m(i) {
    std::cout << "constructor int i = 0" << std::endl;
  };
  int mf(int i) {
    int old = m; 
    m = i;
    return old;
  }
private:
  int m;
};

struct Date {
  int y;
  int m;
  int d;
  Date (int a = 0, int b = 0, int c = 0) : y(a), m(b), d(c) {}
  Date (const Date &d) {
    std::cout << "copy constructor" << std::endl;
    this->d = d.d; 
    m = d.m;
    y = d.y;
  }

  void Init(int dd, int mm, int yy) {
    d = dd; 
    m = mm;
    y = yy;
  }
  void AddYear(int n) { y = y + n; }
  void AddMonth(int n) { m = m + n; }
  void AddDay(int n) { d = d + n; }
};

struct Base {
  virtual void func() {
    std::cout << "Base func" << std::endl;
  }
};

struct Deriv1 : public Base {
  void func() {
    std::cout << "Deriv1 func" << std::endl; 
  }
};

struct Deriv2 : public Base {
  void func() {
    std::cout << "Deriv2 func" << std::endl; 
  }
};

void Func(Base &b) {
  b.func();
}

int XTest();
int DateTest();
int ClassTest();
int main() {
  //XTest();
  //DateTest();
  ClassTest();
}

int ClassTest() {
  Base b = Base();
  Base b1 = Deriv1();
  Base b2 = Deriv2();

  Func(b);
  Func(b1);
  Func(b2);

  return 0;
}

int DateTest() {
  Date d;
  //Date d(); //error
  Date d2(1);
  Date d1{d};
  return 0;
}

int XTest() {
  X var{7};
  return 0;
}
