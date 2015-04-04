#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
int main() {
	int iCount = 3;
	int i = 0;

	for(; i < iCount; i++) {
		pid_t pid = fork();	
		if(pid < 0) {
			fprintf(stderr, "fork failed!\n");	
			exit(1);
		}

		if(pid == 0) {
			/* child */	
			fprintf(stdout, "child, pid = [%d], ppid = [%d]\n", getpid(), getppid());
		}
		else {
			/* parent */	
			fprintf(stdout, "parent, pid = [%d], ppid = [%d]\n", getpid(), getppid());
		}
	}
	sleep(100);
	return 0;
}
