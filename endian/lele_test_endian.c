#include <stdio.h>

int main() {
	int a = 1;
	char *ptr = (char *)(&a);
	for (size_t i = 0; i < sizeof(a); i++) {
		printf("[0x%02x]\n", *(ptr + i));
	}
}
