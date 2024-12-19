#pragma once
#ifndef DICE_H
#define DICE_H
#include<vector>

class Dice {
public:
	Dice() : isRerollCount(0) { dice.resize(5); isReroll.resize(5, true); }

	void setDice(std::vector<int> d) { dice = d; }

	std::vector<int> getDice() { return dice; }
	int getDice(int idx) { return dice[idx]; }

	void setReroll(std::vector<bool> r) { isReroll = r; }
	bool getReroll(int idx) { return isReroll[idx]; }

	void setRerollCount(int t) { isRerollCount = t; }
	int getRerollCount() { return isRerollCount; }

	int getSum() { return dice[0] + dice[1] + dice[2] + dice[3] + dice[4]; }
private:
	std::vector<int> dice;
	std::vector<bool> isReroll;
	int isRerollCount;
};

#endif