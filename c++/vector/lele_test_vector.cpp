#include <iostream>
#include <string>
#include <vector>
#include <cstring>

int main() {
  std::vector<int> vec;
  for (int i = 0; i < 10; i++) {
    vec.push_back(i);
  }

  std::vector<int>::iterator iter = vec.begin();
  for (; iter != vec.end();) {
    std::cout << *iter << std::endl;
    vec.insert(iter, 40);
    std::cout << *iter << std::endl;
    ++iter;
  }
}

