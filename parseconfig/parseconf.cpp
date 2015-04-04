#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <memory.h>
#define BUFF_LEN 4096

char **strmalloc(int);
void parseline(char **, char *);

int main(int argc, char **argv) {
	char strbuff[BUFF_LEN + 1];
	char **p = strmalloc(20);
	char filename[] = "my.conf";
	int fd = open(filename, O_RDONLY);
	if (fd < 0) {
		fprintf(stderr, "open err!\n");
		exit(1);
	}

	while(read(fd, (char *)strbuff, sizeof(strbuff) - 1) > 0) {
		parseline(p, strbuff);
	}

	close(fd);
}

char **strmalloc(int m) {
	char **p = (char **)malloc(sizeof(char)*1024*m);
	if(p == NULL) {
		fprintf(stderr,"malloc err!\n");	
		exit(1);
	}

	return p;
}

void parseline(char **pstrstr, char *str) {
	char *p = str;
}
