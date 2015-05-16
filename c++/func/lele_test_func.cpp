#include <iostream>
#include <string>
using namespace std;
/*
void func(string &s) {
 cout << "string &" << endl;
}
*/

void func(string &&s) {
 cout << "string &&" << endl;
}

void func(const string &s) {
 cout << "const string &" << endl;
}


void func(const string &&s) {
 cout << "const string &&" << endl;
}

void func1(const string &s, int i = 100) {
 cout << "const string &, int" << endl;
}

void func1(const string &s, bool i = true) {
 cout << "const string &, bool" << endl;
}

void func1(const string &s, string s1) {
 cout << "const string &, string" << endl;
}

/*
void func1(const string &s, char i = 'a') {
 cout << "const string &, char" << endl;
}
*/

int main() {
  string s;
  func(s);
  const string s1;
  func(s1);
  func("a");
  func1(s, 'a');
  return 0;
}
