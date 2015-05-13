#include <iostream>
#include <iomanip>

int main(int argc, char **argv) {
	int a = 0x01020304;
	char *ptr = (char *)(&a);
	for (size_t i = 0; i < sizeof(a); i++) {
    std::cout << "addr = [0x" << static_cast<const void *>(ptr + i) << "], value = [0x" 
      << std::setfill('0') << std::setw(2) << static_cast<int>(*(ptr + i)) << "]" << std::endl;
	}

  return 0;
}
