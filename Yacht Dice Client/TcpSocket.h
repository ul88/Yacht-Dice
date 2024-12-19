#pragma once
#ifndef TCPSOCKET_H
#define TCPSOCKET_H
#include<WinSock2.h>
#include<ws2tcpip.h>
#pragma comment(lib,"ws2_32.lib")

#define PORT 4444

class TcpSocket {
public:
	TcpSocket(SOCKET sock);

	void Connect(sockaddr_in& sock_addr);
	void Bind(sockaddr_in& sock_addr);
	void Listen();
	TcpSocket Accept(sockaddr_in& from_addr);
	int Send(void* data, int len);
	int Recv(void* data, int len);

	~TcpSocket() { closesocket(m_sock); }

private:
	SOCKET m_sock;
};

#endif