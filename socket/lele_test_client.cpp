#define VAR_GCC_
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <string.h>
#ifdef VAR_GCC_
#include <unistd.h>
#include <fcntl.h>
#endif
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h> /* struct sockaddr_in */
#include <arpa/inet.h> /* inet_pton */

int main(int argc, char **argv) {
    /**
     * argv[0] 程序名称
     * argv[1] 发往IP地址
     * argv[2] 发往端口
     */
    if (3 != argc) {
        std::cout << "please using <client> <IPaddr> <port>" << std::endl;
        return -1;
    }

    std::string strIPAddr = argv[1];
    unsigned short usPort = atoi(argv[2]);

    // 准备socket
    int nSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (-1 == nSocket) {
        std::cerr << "socket() error" << std::endl;
        return -1;
    }

    // 填充IP地址和端口
    struct sockaddr_in stSockAddr;
    memset(&stSockAddr, 0x00, sizeof(stSockAddr));
    stSockAddr.sin_family = AF_INET;
    stSockAddr.sin_port = htons(usPort);
    int nRet = 0;
    nRet = inet_pton(AF_INET, strIPAddr.c_str(), &stSockAddr.sin_addr);
    if (nRet == -1) {
        std::cerr << "inet_pton() error" << std::endl;
        return -1;
    }

    // 建立连接
    nRet = connect(nSocket, (sockaddr *)&stSockAddr, sizeof(stSockAddr));
    if (-1 == nRet) {
        std::cerr << "connect error" << std::endl;
        return -1;
    }

	int opt_sendbuf_size = 4;
	size_t opt_len = sizeof(int);
	nRet = setsockopt(nSocket, SOL_SOCKET, SO_SNDBUF, &opt_sendbuf_size, opt_len);
	if (nRet)
	{
		std::cerr << "setsockopt invoked error!" << std::endl;
		return -1;
	}

	struct timeval tv;
	socklen_t len;
	nRet = getsockopt(nSocket, SOL_SOCKET, SO_RCVTIMEO, (void *)&tv, &len);
	if (nRet)
	{
		std::cerr << "getsockopt invoked error!" << std::endl;
		return -1;
	}
	printf("%ld, %ld\n", tv.tv_sec, tv.tv_usec);

    const int nMaxBuffSize = 4096;
    char czBuff[nMaxBuffSize] = {0};
    std::size_t nRead = 0;
	std::size_t nWrite = 0;
	while(1)
	{
		nRead = read(STDIN_FILENO, czBuff, nMaxBuffSize);
		czBuff[nRead - 1] = '\0';
		printf("write [%s][%ld] to socket\n", czBuff, nRead);
		nWrite = write(nSocket, czBuff, nRead);
		read(nSocket, czBuff, nWrite);	
		printf("read [%s][%ld] from socket\n", czBuff, nRead);
	}
    close(nSocket);
    return 0;
}
