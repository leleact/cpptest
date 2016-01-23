#include <iostream>
int main(int argc, char *argv[]) {
	srand(time(nullptr));

	for (int i = 0; i < 20; ++i)
		std::cout << rand() << " ";

	std::cout << std::endl;
	return 0;
}
