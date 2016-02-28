#include <iostream>

class A {

    static int i ;

};


int A::i = 100;

int main() {
    std::cout << A::i << std::endl;
}
