#include <iostream>

template <int N>
struct Fibonacci {
    constexpr static long value = Fibonacci<N-1>::value + Fibonacci<N - 2>::value;
};

template <>
struct Fibonacci<1> {
    constexpr static long value = 1;
};

template <>
struct Fibonacci<0> {
    constexpr static long value = 0;
};


int main() {
    std::cout << "Fibonacci<0>:" << Fibonacci<0>::value << std::endl;
    std::cout << "Fibonacci<1>:" << Fibonacci<1>::value << std::endl;
    std::cout << "Fibonacci<80>:" << Fibonacci<80>::value << std::endl;
    std::cout << "Fibonacci<81>:" << Fibonacci<81>::value << std::endl;
    std::cout << "Fibonacci<82>:" << Fibonacci<82>::value << std::endl;
    std::cout << "Fibonacci<83>:" << Fibonacci<83>::value << std::endl;
    std::cout << "Fibonacci<84>:" << Fibonacci<84>::value << std::endl;
    std::cout << "Fibonacci<85>:" << Fibonacci<85>::value << std::endl;
    std::cout << "Fibonacci<86>:" << Fibonacci<86>::value << std::endl;
    std::cout << "Fibonacci<87>:" << Fibonacci<87>::value << std::endl;
    std::cout << "Fibonacci<88>:" << Fibonacci<88>::value << std::endl;
    std::cout << "Fibonacci<89>:" << Fibonacci<89>::value << std::endl;
    std::cout << "Fibonacci<90>:" << Fibonacci<90>::value << std::endl;
    std::cout << "Fibonacci<91>:" << Fibonacci<91>::value << std::endl;
    std::cout << "Fibonacci<92>:" << Fibonacci<92>::value << std::endl;
}
