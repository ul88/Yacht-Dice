#pragma once
#ifndef DICE_H
#define DICE_H
#include<vector>
#include<random>

class Dice {
public:
	Dice() : isRerollCount(3) { dice.resize(5); isReroll.resize(5, true); }
	std::vector<int> getDice() { return dice; }
	int getDice(int idx) { return dice[idx]; }

	int getSum() { return dice[0] + dice[1] + dice[2] + dice[3] + dice[4]; }

	void setReroll(int index) { isReroll[index] = !isReroll[index]; }
	int getReroll(int index) { return isReroll[index]; }

	void decreaseRerollCount() { isRerollCount--; }
	void setRerollCount(int count) { isRerollCount = count; }
	int getRerollCount() { return isRerollCount; }

	void initDice() {
		isRerollCount = 3;
		std::fill(dice.begin(), dice.end(), 0);
		std::fill(isReroll.begin(), isReroll.end(), true);
	}

	void rollDice(std::mt19937& gen);
private:
	std::vector<int> dice;
	std::vector<bool> isReroll;
	int isRerollCount;
};

#endif