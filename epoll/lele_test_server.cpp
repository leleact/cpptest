#include <iostream>
#include <stdio.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

const int nMaxEvent = 2;

void setnonblocking(int fd);
int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cerr << "please use <server> <port>!" << std::endl;	
		return -1;
	}

	struct epoll_event ev, events[nMaxEvent];
	int epfd = epoll_create(0xFF);
	if (epfd < 0)
	{
		std::cerr << "epoll_create error!" << std::endl;
		return -1;
	}

	struct sockaddr_in clientaddr, serveraddr;
	socklen_t socklen = sizeof(clientaddr);
	int listenfd = socket(AF_INET, SOCK_STREAM, 0);
	if (listenfd < 0)
	{
		std::cerr << "socket error!" << std::endl;
		return -1;
	}

	setnonblocking(listenfd);

	ev.data.fd = listenfd;
	ev.events = EPOLLIN|EPOLLET;
	int ret = epoll_ctl(epfd, EPOLL_CTL_ADD, listenfd, &ev);
	if (ret)
	{
		std::cerr << "epoll_ctl error!"	 << std::endl;
		return -1;
	}

	bzero(&serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	inet_aton((char *)"0.0.0.0", &serveraddr.sin_addr);
	serveraddr.sin_port = htons(atoi(argv[1]));

	ret = bind(listenfd, (sockaddr *)&serveraddr, sizeof(serveraddr));
	if (ret)
	{
		std::cerr << "bind error!" << std::endl;
		return -1;
	}

	ret = listen(listenfd, 64);
	if (ret)
	{
		std::cerr << "listen error!" << std::endl;
		return -1;
	}

	while(1)
	{
		int nfds = 0;
		nfds = epoll_wait(epfd, events, nMaxEvent, -1);
		std::cout << "epoll_wait return nfds[" << nfds << "]" << std::endl;
		for (int i = 0; i < nfds; ++i)
		{
			if (events[i].data.fd == listenfd)
			{
				std::cout << "有客户端连接[" << i << "]" << std::endl;	
				int connfd = accept(listenfd, (sockaddr *)&clientaddr, &socklen);
				if (connfd < 0)
				{
					std::cerr << "accept error !" << std::endl;
					continue;
				}
				setnonblocking(connfd);
				std::cout << "accept a connection from [" << inet_ntoa(clientaddr.sin_addr) << "]" << std::endl;
				ev.data.fd = connfd;
				ev.events = EPOLLIN|EPOLLET;
				ret = epoll_ctl(epfd, EPOLL_CTL_ADD,connfd,&ev);
				if (ret)
				{
					std::cerr << "epoll_ctl error !" << std::endl;	
					continue;
				}
			}
			else if (events[i].events & EPOLLIN)
			{
				std::cout << "EPOLLIN" << std::endl;
				char strBuff[1024] = {'\0'};
				int n = 0;
				int nRecv = 0;
				while((nRecv = recv(events[i].data.fd, strBuff + n, 1024 - n, 0)) > 0)
				{
					n = n + nRecv;	
				}

				if (nRecv == -1 && errno != EAGAIN) {
					std::cout << "epoll_ctl_del: " << events[i].data.fd << ",errno: " << errno << ",msg:" << strerror(errno) << std::endl;
					epoll_ctl(epfd, EPOLL_CTL_DEL, events[i].data.fd, &ev);
					close(events[i].data.fd);
					events[i].data.fd = -1; // INVALID SOCKET
					continue;
				}
				if (nRecv == 0) {
					std::cout << "epoll_ctl_del: " << events[i].data.fd << " closed" <<  std::endl;
					epoll_ctl(epfd, EPOLL_CTL_DEL, events[i].data.fd, &ev);
					close(events[i].data.fd);
					events[i].data.fd = -1; // INVALID SOCKET
					continue;
				}
				sockaddr_in socketaddr1;
				socklen_t socketlen1;
				getsockname(events[i].data.fd, (sockaddr *)&socketaddr1, &socketlen1);
				std::cout << "strBuff[" << strBuff << "], port:" << socketaddr1.sin_port << std::endl;
				ev.data.fd = events[i].data.fd;
				ev.events = events[i].events | EPOLLOUT | EPOLLIN;
				ret = epoll_ctl(epfd, EPOLL_CTL_MOD, events[i].data.fd, &ev);
				if (ret)
				{
					std::cerr << "epoll_ctl error !"	<< std::endl;
					continue;
				}
			}
			else if (events[i].events & EPOLLOUT)
			{
				sleep(3);
				std::cout << "EPOLLOUT" << std::endl;
			}
		}
	}
}

void setnonblocking(int fd)
{
	int opts;
	opts = fcntl(fd, F_GETFL);
	if (opts < 0)
	{
		perror("fcntl error");	
		exit(1);
	}

	opts |= O_NONBLOCK;
	if (fcntl(fd, F_SETFL, opts) < 0)
	{
		perror("fcntl(sock,SETFL,opts)");	
		exit(1);
	}
}
