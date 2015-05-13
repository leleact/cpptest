#include <iostream>
int main() {
  srand(time(nullptr));
	for (int i = 0; i < 20; i++) {
		printf("[%d]\n", rand());	
	}
	return 0;
}
