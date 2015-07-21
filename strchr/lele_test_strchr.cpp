#include <iostream>
#include <cstring>
int main(int argc, char *argv[])
{
	for (int i = 0; i < argc; ++i)
	{
		std::cout << "argv[" << i << "][" << argv[i] << "]"	<< std::endl;
	}

	char *pstr = argv[1];
	char cDot = argv[2][0];
    char *p1 = strchr(pstr, cDot);
    char *p2 = strchr(p1 + 1, cDot);
	int offset = p2 - p1;
	char strOrgiMsgType[10];
	strncpy(strOrgiMsgType, p1 + 1, offset - 1);
	std::cout << strOrgiMsgType << std::endl;
	int nOrgiMsgType = atoi(strOrgiMsgType);
	std::cout << nOrgiMsgType << std::endl;
    return 0;
}
