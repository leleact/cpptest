#include <iostream>
#include <utility>
#include <vector>
#include <iomanip>
#define CLASS_X
#define DEBUG
#ifdef CLASS_X
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
  X(string &&s) : s(std::move(s)) {}
  X& operator=(const X &x) {
    s = x.s; 
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
  X x1 = "aa";
  X x2 = "bb";
  std::vector<X> xvec;
  xvec.push_back(x1);
  xvec.push_back(std::move(x2));

  for (X& x : xvec) std::cout << x << " ";
  std::cout << std::endl;

  std::cout << "x1 = [" << x1 << "], x2 = [" << x2 << "]" << std::endl;

  return 0;
}
