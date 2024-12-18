#include<iostream>
#include"YachtBoard.h"
int main()
{
	Dice d;
	Player player1;
	Player player2;

	YachtBoard yachtBoard(&player1, &player2, &d);

	yachtBoard.printBoard();

	return 0;
}