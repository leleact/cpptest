#include <stdio.h>

int main() {
	int a = 0x01020304;
	char *ptr = (char *)(&a);
	for (size_t i = 0; i < sizeof(a); i++) {
		printf("addr = [0x%lx], value = [0x%02x]\n", (unsigned long)(ptr + i), *(ptr + i));
	}
}
