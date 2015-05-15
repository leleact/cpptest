#include <iostream>
#include <string>
using namespace std;
int main(int argc, char **argv) {
  const string str = "keep out!";
  for (auto &c : str) {
    cout << c << endl; 
  }

  return 0;
}
