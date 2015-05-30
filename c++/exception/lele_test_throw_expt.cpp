#include <iostream>
#include <vector>
#include <exception>
#include <string>

class TestException : public std::exception {
public:
  /*
  TestException() throw() {
    std::cout << "TestException" << std::endl;
  }
  */

  virtual const char * what() const throw() override {
    return "exception caught";
  };
};

void func() throw (std::string) ;

int main() {
  std::string str = "aaa";

try {
  func();
} /* catch( std::vector<int>() ) {
  std::cout << "11" << std::endl;
}
*/
catch (std::string e) {
  std::cout << "std::string exception" << std::endl;
}
catch (int n) {
  std::cout << "int exception" << std::endl;
}
  /*
  if (str == "aaa") {
    throw std::string(); 
  }
  */

  return 0;
}


void func() throw (std::string) {
  std::cout << "func called" << std::endl;
  if (1)
    // throw int(); // 直接退出, 不能捕获
    throw std::string("hehe"); // 可以被捕获与处理
}
