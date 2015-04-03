#include <iostream>
#define LINT int
#define LCHAR char
int main(LINT argc, LCHAR **argv) {
	for (int i = 0; i < argc; i++) {
		std::cout << "第[" << i + 1 << "]个参数是[" << *(argv + i) << "]" << std::endl;
	}
	std::cout << "Hello World!" << std::endl;
	return 0;
}
