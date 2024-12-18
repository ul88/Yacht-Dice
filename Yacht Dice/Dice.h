#pragma once
#ifndef DICE_H
#define DICE_H
#include<vector>

class Dice {
public:
	Dice() { dice.resize(5); }

	std::vector<int> getDice() { return dice; }
	int getDice(int idx) { return dice[idx]; }

	int getSum() { return dice[0] + dice[1] + dice[2] + dice[3] + dice[4]; }
private:
	std::vector<int> dice;
};

#endif