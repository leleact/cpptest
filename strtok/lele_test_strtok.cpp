#include <iostream>
#include <cstring>

int main(int argc, char **argv) {
	char src[] = "The world is beautiful";

	char *pstr = strtok(src, " ");
	//cout << pstr << endl;
	while(pstr != nullptr) {
		std::cout << pstr << std::endl;
		pstr = strtok(nullptr, " ");
	}

	return 0;
}
