#include <iostream>
template<typename T>
struct X {
  typedef T type;
};

template<typename T>
struct X<T &> {
 typedef T type; 
};

template<>
struct X<char> {
  typedef char type;
};

int main() {
}
