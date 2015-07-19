#include <iostream>
#include <cstring>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int c;
	int a_flag = 0;
	int b_flag = 0;
	char c_value[10];
	char d_value[10];
	while((c = getopt(argc, argv, "abc:d:")) != -1)
	{
		switch(c)	
		{
		case 'a': 
			a_flag = 1;
			break;
		case 'b':
			b_flag = 1;
			break;
		case 'c':
			strncpy(c_value, optarg, 10);
			break;
		case 'd':
			strncpy(d_value, optarg, 10);
			break;
		default:
			fprintf(stderr, "error");
		}
	}

	printf("a_flag[%d], b_flag[%d], c_value[%s], d_value[%s]\n", a_flag, b_flag, c_value, d_value);
	return -1;
}
