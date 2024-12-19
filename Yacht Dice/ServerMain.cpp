#include<iostream>
#include<cstring>
#include"Serialization.h"
#include"TcpSocket.h"
#include"ScoreBoard.h"

std::random_device rd;
std::mt19937 gen(rd());

int recvFromPlayer(TcpSocket& player_sock, ScoreBoard& board, Dice& d) {
	int num;
	char flag;
	player_sock.Recv((void*)&flag, sizeof(flag));
	std::cout << "flag: " << flag << "\n";
	switch (flag) {
	case 'd':
		player_sock.Recv((void*)&num, sizeof(num));
		std::cout << "num: " << num << "\n";
		if (num == 6) {
			if (d.getRerollCount() != 0) {
				d.rollDice(gen);
				d.decreaseRerollCount();
				board.checkHand(d);
			}
		}
		else if(d.getRerollCount() != 3 && num <= 5 && num >= 1) {
			d.setReroll(num - 1);
			for (int i = 0;i < 5;i++) {
				std::cout << d.getReroll(i) << " ";
			}
		}
		break;
	case 's':
		player_sock.Recv((void*)&num, sizeof(num));
		if (board.setScoreBoard(static_cast<YachtHand>(num))) {
			d.initDice();
			flag = 'g';
			player_sock.Send((void*)&flag, sizeof(flag));
			return 1;
		}
		break;
	}
	flag = 'r';
	player_sock.Send((void*)&flag, sizeof(flag));
	return 0;
}

int main()
{
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) exit(1);
	
	TcpSocket sock(::socket(AF_INET, SOCK_STREAM, 0));
	sockaddr_in sock_addr{AF_INET, htons(PORT)};
	sock_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	sock.Bind(sock_addr);
	sock.Listen();

	char addr[INET_ADDRSTRLEN];
	sockaddr_in player1_addr, player2_addr;
	TcpSocket player1_sock = sock.Accept(player1_addr);
	std::cout << "player1 접속 완료: "
		<< inet_ntop(AF_INET, &player1_addr.sin_addr, addr, sizeof(addr))
		<< ":" << htons(player1_addr.sin_port) << std::endl;
	TcpSocket player2_sock = sock.Accept(player2_addr);
	std::cout << "player2 접속 완료: "
		<< inet_ntop(AF_INET, &player2_addr.sin_addr, addr, sizeof(addr))
		<< ":" << htons(player2_addr.sin_port) << std::endl;
	std::cout << "플레이어 연결 완료\n";

	//플레이어 확인 신호 보냄
	player1_sock.Send((void*)"player1", sizeof("player1"));
	player2_sock.Send((void*)"player2", sizeof("player2"));

	ScoreBoard p1_board;
	ScoreBoard p2_board;
	Dice d;
	int turn = 0; // 짝수: player1, 홀수: player2, 현재 턴수 isTurn/2 + 1;
	while (turn < 23) {
		type t = Serialization::output(p1_board, p2_board, d, turn);
		player1_sock.Send((void*)&t, sizeof(t));
		player2_sock.Send((void*)&t, sizeof(t));

		if (turn % 2 == 0) {
			turn += recvFromPlayer(player1_sock, p1_board, d);
		}
		else {
			turn += recvFromPlayer(player2_sock, p2_board, d);
		}
	}

	return 0;
}