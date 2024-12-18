#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include<vector>
#include"ScoreBoard.h"

class Player {
public:
	Player() : score(0), isTurn(false) { selectDice.resize(5, 0); }
	
	void changeTurn() { isTurn = !isTurn; } // 현재 게임을 진행할 플레이어

	std::vector<int> getSb() { return sb.getScoreBoard(); } // 플레이어가 가지고 있는 스코어보드 전달
private:
	int score;
	bool isTurn;
	std::vector<bool> selectDice;
	ScoreBoard sb;
};

#endif