#include <iostream>
enum ERR_CODE
{
	START,
	END
};

void fun1(ERR_CODE &errcode)
{
	std::cout << errcode << std::endl;
}

int main()
{
	ERR_CODE a;
	a = END;
	std::cout << a << std::endl;

	fun1(a);
	return 0;
}
