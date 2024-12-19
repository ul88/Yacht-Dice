#include"Serialization.h"
type Serialization::output(ScoreBoard p1, ScoreBoard p2, Dice d, int turn) {
	type new_type;
	new_type.turn = turn;
	new_type.rerollCount = d.getRerollCount();

	//player1 scoreboard
	std::vector<int> temp = p1.getScoreBoard();
	for (int i = 0;i < temp.size();i++) {
		new_type.sb1[i] = temp[i];
	}

	//player2 scoreboard
	temp = p2.getScoreBoard();
	for (int i = 0;i < temp.size();i++) {
		new_type.sb2[i] = temp[i];
	}

	//player1 tempboard
	temp = p1.getTempBoard();
	for (int i = 0;i < temp.size();i++) {
		new_type.tb1[i] = temp[i];
	}

	//player2 tempboard
	temp = p2.getTempBoard();
	for (int i = 0;i < temp.size();i++) {
		new_type.tb2[i] = temp[i];
	}

	//dice
	for (int i = 0;i < 5;i++) {
		new_type.d[i] = d.getDice(i);
	}

	//select dice
	for (int i = 0;i < 5;i++) {
		new_type.sd[i] = d.getReroll(i);
	}

	return new_type;
}