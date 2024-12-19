#include"Dice.h"

void Dice::rollDice(std::mt19937& gen) {
	std::uniform_int_distribution<int> dis(1, 6);
	for (int i = 0;i < dice.size();i++) {
		if (isReroll[i])
			dice[i] = dis(gen);
	}
}