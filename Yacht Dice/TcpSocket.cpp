#include"TcpSocket.h"

void TcpSocket::Connect(sockaddr_in& sock_addr) {
	if (::connect(m_sock, (sockaddr*)&sock_addr, sizeof(sock_addr)) == SOCKET_ERROR) exit(1);
}

void TcpSocket::Bind(sockaddr_in& sock_addr) {
	if (::bind(m_sock, (sockaddr*)&sock_addr, sizeof(sock_addr)) == SOCKET_ERROR) exit(1);
}

void TcpSocket::Listen() {
	if (::listen(m_sock, SOMAXCONN) == SOCKET_ERROR) exit(1);
}

TcpSocket TcpSocket::Accept(sockaddr_in& from_addr) {
	int addr_size = sizeof(from_addr);

	SOCKET new_sock = ::accept(m_sock, (sockaddr*)&from_addr, &addr_size);
	if (new_sock == INVALID_SOCKET) exit(1);

	return TcpSocket(new_sock);
}

int TcpSocket::Send(void* data, int len) {
	int ret = send(m_sock, static_cast<const char*>(data), len, 0);

	if (ret >= 0) return ret;
	return -1;
}

int TcpSocket::Recv(void* data, int len) {
	int ret = recv(m_sock, static_cast<char*>(data), len, 0);

	if (ret >= 0) return ret;
	return -1;
}