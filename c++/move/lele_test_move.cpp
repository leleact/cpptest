#include <iostream>
#include <utility>
#include <vector>
#include <iomanip>
#define DEBUG
#ifndef USING_STD_STRING
class X {
using string = std::string;
public:
  X() = default;
  X(const string &s) : s(s) {};
  X(const char *p) {
#ifdef DEBUG
    std::cout << "const char *p" << std::endl;
#endif
    s = std::move(string(p)); 
  }
  X(string &&s) : s(std::move(s)) {
#ifdef DEBUG
    std::cout << "string && move" << std::endl;
#endif
  }
  X(const X &x) : s(x.s) {}
  X(X&& x) : s(std::move(x.s)) {
#ifdef DEBUG
    std::cout << "X&& move" << std::endl;
#endif
  }
  X& operator=(const X &x) {
    s = x.s; 
    return *this;
  }
  X& operator=(X&& x) {
    s = std::move(x.s);
    return *this;
  }

  friend std::ostream& operator<<(std::ostream &os, X &x) {
    os << x.s; 
    return os;
  }
private:
  string s;
};
#else
using X = std::string;
#endif
int main() {
  std::string s1 = "aa";
  std::string s2 = "bb";
  X x1 = "aa";
  X x2 = "bb";
  X x3(s1);
  X x4(s2);
  std::vector<X> xvec;
  xvec.push_back(x1);
  xvec.push_back(std::move(x2));
  xvec.push_back(x3);
  xvec.push_back(std::move(x4));

  for (X& x : xvec) std::cout << x << " ";
  std::cout << std::endl;

  std::cout << "x1 = [" << x1 << "], x2 = [" << x2 << "]" << std::endl;
  std::cout << "x3 = [" << x3 << "], x4 = [" << x4 << "]" << std::endl;

  return 0;
}
