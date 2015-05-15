#include <iostream>
#include <string>
using namespace std;
int InitString(int, char **);
int LoopString(int, char **);

int main(int argc, char **argv) {
  InitString(argc, argv);
  LoopString(argc, argv);
  return 0;
}

int LoopString(int argc, char **argv) {
  const string str = "Hello World";
  for (auto &c : str)
    cout << c << endl;

  return 0;
}

int InitString(int argc, char **argv) {
  //Initialize string
  string s1;
  string s2 = s1;
  string s3 = "Hello";
  string s4(10, 'a');
  string s5(s3);
  string s6("World");


  std::cout << "s1 = [" << s1 << "]" << std::endl;
  std::cout << "s2 = [" << s2 << "]" << std::endl;
  std::cout << "s3 = [" << s3 << "]" << std::endl;
  std::cout << "s4 = [" << s4 << "]" << std::endl;
  std::cout << "s5 = [" << s5 << "]" << std::endl;
  std::cout << "s6 = [" << s6 << "]" << std::endl;

  std::cin >> s1 >> s3;
  std::cout << "s1 = [" << s1 << "]" << std::endl;
  std::cout << "s3 = [" << s3 << "]" << std::endl;

  return 0;
}
