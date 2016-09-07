#include <iostream>

template <typename T>
class Base {
    public:
        void func () {
            static_cast<T *>(this)->func();
        }
};

class Derive1 : public Base<Derive1> {
    public:
        void func() const {
            std::cout << __PRETTY_FUNCTION__ << std::endl;
        }
};

class Derive2 : public Base<Derive2> {
    public:
        void func() const {
            std::cout << __PRETTY_FUNCTION__ << std::endl;
        }
};

int main(int argc, char *argv[]) {
    Base<Derive1> *b1 = new Derive1(); 
    Base<Derive2> *b2 = new Derive2(); 

    b1->func();
    b2->func();

    delete b1;
    delete b2;
}
