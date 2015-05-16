#include <iostream>
#include <vector>
using namespace std;

template<typename T>
struct X {
  T type_value;
  vector<T> t_vec{10};
  auto fun() -> decltype(*t_vec.begin()){
    auto iter = t_vec.begin();
    return *iter;
  }
};

int main(int argc, char **) {
  vector<string> svec{10};
  auto iter = svec.begin();
  X<int> x;
  cout << x.fun() << endl;
  return 0;
}
