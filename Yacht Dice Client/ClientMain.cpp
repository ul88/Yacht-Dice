#include<iostream>
#include"TcpSocket.h"
#include"YachtBoard.h"
#include"Deserialization.h"
#define SERVERIP "127.0.0.1"

void inputDice(TcpSocket& sock, int rerollCount) {
	int num;
	char flag = 'd';
	if (rerollCount != 0) {
		std::cout << std::endl;
		std::cout << "�ֻ����� �����ϰ� �ʹٸ� 1~5������ ���ڸ� �Է����ּ���." << std::endl;
		std::cout << "������ �ϰ� �ʹٸ� 6�� �������ּ���.( ���� ���� ����: "
			<< rerollCount << ")" << std::endl;
		std::cout << "Ȯ���� �ϰ� �ʹٸ� 7�� �������ּ���." << std::endl;
		std::cin >> num;
		sock.Send((void*)&flag, sizeof(flag));
		sock.Send((void*)&num, sizeof(num));
		sock.Recv((void*)&flag, sizeof(flag));
		if (flag == 'r') return;
	}
	else {
		// �� ����
		std::cout << std::endl;
		std::cout << "1~12������ ���� �������ּ���.(Bonus ���� �������)" << std::endl;
		std::cout << "*�� �پ��ִ� ���� ������ �����մϴ�." << std::endl;
		std::cin >> num;
		flag = 's';
		sock.Send((void*)&flag, sizeof(flag));
		sock.Send((void*)&num, sizeof(num));
		sock.Recv((void*)&flag, sizeof(flag));
		if (flag == 'g') std::cout << std::endl << "���� ��� ���Դϴ�." << std::endl;
	}
}

int main()
{
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) exit(1);

	TcpSocket sock(::socket(AF_INET, SOCK_STREAM, 0));
	sockaddr_in sock_addr{ AF_INET, htons(PORT) };
	inet_pton(AF_INET, SERVERIP, &sock_addr.sin_addr);

	sock.Connect(sock_addr);
	char temp[100];
	sock.Recv(temp, 100);

	std::string playerName = temp;
	std::cout << playerName << "�Դϴ�."<<std::endl;
	
	Player p1;
	Player p2;
	Dice d;
	YachtBoard board(&p1, &p2, &d);

	while (board.getTurn() <= 23) {
		type t;
		sock.Recv((void*)&t, sizeof(t));

		Deserialization::output(board, p1, p2, d, t);
		board.printBoard();

		if (playerName == "player1" && board.getTurn() % 2 == 0) {
			inputDice(sock, d.getRerollCount());
		}
		if (playerName == "player2" && board.getTurn() % 2 == 1) {
			inputDice(sock, d.getRerollCount());
		}
	}

	char name[100];
	int score;
	sock.Recv(name, 100);
	sock.Recv((void*)&score, sizeof(score));

	std::cout << "���ڴ� " << name << std::endl;
	std::cout << "������ " << score << "�� �Դϴ�." << std::endl;

	WSACleanup();
	return 0;
}