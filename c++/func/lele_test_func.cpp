#include <iostream>
#include <string>
using namespace std;
void func(string &s) {
 cout << "string &" << endl;
}

void func(string &&s) {
 cout << "string &&" << endl;
}

void func(const string &s) {
 cout << "const string &" << endl;
}

void func(const string &&s) {
 cout << "const string &&" << endl;
}

int main() {
  string s;
  func(s);
  const string s1;
  func(s1);
  func("a");
  return 0;
}
