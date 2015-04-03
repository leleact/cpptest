#include <stdio.h>
#include <string.h>
int main() {
	char s[5];

	//memcpy(s, "Hello", 5); //Hell
	memcpy(s, "Hello", 10); //CoreDump

	printf("s = [%s]\n", s);

}
