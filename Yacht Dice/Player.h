#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include<vector>
#include"ScoreBoard.h"

class Player {
public:
	Player() : score(0), isTurn(false) { selectDice.resize(5, 0); }
	
	void changeTurn() { isTurn = !isTurn; } // ���� ������ ������ �÷��̾�

	std::vector<int> getSb() { return sb.getScoreBoard(); } // �÷��̾ ������ �ִ� ���ھ�� ����
private:
	int score;
	bool isTurn;
	std::vector<bool> selectDice;
	ScoreBoard sb;
};

#endif