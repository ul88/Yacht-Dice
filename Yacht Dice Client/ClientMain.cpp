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
		std::cout << "주사위를 선택하고 싶다면 1~5까지의 숫자를 입력해주세요." << std::endl;
		std::cout << "리롤을 하고 싶다면 6을 선택해주세요.( 남은 리롤 개수: "
			<< rerollCount << ")" << std::endl;
		std::cout << "확정을 하고 싶다면 7을 선택해주세요." << std::endl;
		std::cin >> num;
		sock.Send((void*)&flag, sizeof(flag));
		sock.Send((void*)&num, sizeof(num));
		sock.Recv((void*)&flag, sizeof(flag));
		if (flag == 'r') return;
	}
	else {
		// 값 선택
		std::cout << std::endl;
		std::cout << "1~12까지의 값을 선택해주세요.(Bonus 제외 순서대로)" << std::endl;
		std::cout << "*이 붙어있는 값만 수정이 가능합니다." << std::endl;
		std::cin >> num;
		flag = 's';
		sock.Send((void*)&flag, sizeof(flag));
		sock.Send((void*)&num, sizeof(num));
		sock.Recv((void*)&flag, sizeof(flag));
		if (flag == 'g') std::cout << std::endl << "이제 상대 턴입니다." << std::endl;
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
	std::cout << playerName << "입니다."<<std::endl;
	
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

	std::cout << "승자는 " << name << std::endl;
	std::cout << "점수는 " << score << "점 입니다." << std::endl;

	WSACleanup();
	return 0;
}