#pragma once
#ifndef SERIALIZATION_H
#define SERIALIZATION_H
#include<vector>
#include"ScoreBoard.h"
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

class Serialization {
public:
	static type output(ScoreBoard p1, ScoreBoard p2, Dice d, int turn);
};

#endif