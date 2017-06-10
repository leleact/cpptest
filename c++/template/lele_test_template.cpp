#include <iostream>
namespace v1 {
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
    return 0;
}
}

namespace v2 {

class Increaser {
friend std::ostream& operator << (std::ostream& os, const Increaser& i) { return os; }
public:
    Increaser& increase(const Increaser& i) { return *this; }
};

template <typename InCrT>
InCrT increase(InCrT v1, InCrT v2) {
    return v1.increase(v2);
}

template <>
int increase<int>(int v1, int v2) {
    return v1 + v2;
}

}

int main(int argc, char *argv[]) {
    {
        v2::Increaser v1;
        v2::Increaser v2;
        std::cout << v2::increase(v1, v2) << std::endl;
    }

    {
        int i1 = 1; 
        int i2 = 2;
        std::cout << v2::increase(i1, i2) << std::endl;
    }
    return 0;
}
