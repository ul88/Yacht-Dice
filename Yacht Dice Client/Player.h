#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include<iostream>
#include<vector>
#include"YachtHand.h"

class Player {
public:
	void setScoreBoard(std::vector<int> v1, std::vector<int> v2);
	int getScoreBoard(YachtHand yh) { return m_scoreBoard[static_cast<int>(yh)]; }

	int getTempBoard(YachtHand yh) { return m_tempBoard[static_cast<int>(yh)]; }
private:
	std::vector<int> m_scoreBoard;
	std::vector<int> m_tempBoard;
};

#endif