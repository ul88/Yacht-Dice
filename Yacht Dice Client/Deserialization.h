#pragma once
#ifndef DESERIALIZATION_H
#define DESERIALIZATION_H
#include<vector>
#include<cstring>
#include"YachtBoard.h"
#include"YachtHand.h"
#define BUFSIZE 1024

struct type {
	int turn;
	int sb1[static_cast<int>(YachtHand::SIZE)];
	int sb2[static_cast<int>(YachtHand::SIZE)];
	int tb1[static_cast<int>(YachtHand::SIZE)];
	int tb2[static_cast<int>(YachtHand::SIZE)];
	int d[5];
	bool sd[5];
	int rerollCount;
};

class Deserialization {
public:
	static void output(YachtBoard& board, Player& player1, Player& player2, 
		Dice& d, type& t);
};

#endif