// 测试struct类的继承方式
#include <iostream>
#include <string>
struct A
{
	int a;
};

class B : A
{
public:
	B(int b) : b(b) {}

private:
	int b;

};


int main()
{
	B b(4);

	std::cout << b.a << std::endl;
}

// 看来默认继承还是私有继承嘛
