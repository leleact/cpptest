#define VAR_GCC_
#include <iostream>
#include <string>
#include <cstring>
#include <string.h>
#ifdef VAR_GCC_
#include <unistd.h>
#include <fcntl.h>
#endif
#include <sys/socket.h>
#include <netinet/in.h> /* struct sockaddr_in */
#include <arpa/inet.h> /* inet_pton */

int main(int argc, char **argv) {
  /**
   * argv[0] 程序名称
   * argv[1] 发往IP地址
   * argv[2] 发往端口
   * argv[3] 发送文件名称
   */
  if (4 != argc) {
    std::cout << "please using <client> <IPaddr> <port> <filename>" << std::endl;
    return -1;
  }

  std::string strIPAddr = argv[1];
  unsigned short usPort = atoi(argv[2]);
  std::string strFileName = argv[3];

  int nFd = open(strFileName.c_str(), O_RDONLY);
  if (nFd <= 0) {
    std::cerr << "open error" << std::endl;
    return -1;
  }

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

  const int nMaxBuffSize = 4096;
  char czBuff[nMaxBuffSize] = {0};
  std::size_t nRead = 0;
  while((nRead = read(nFd, czBuff, sizeof(czBuff))) != 0) {
    write(nSocket, czBuff, nRead); 
  }

  close(nSocket);
  close(nFd);

  return 0;
}
