#pragma once
#ifndef SCOREBOARD_H
#define SCOREBOARD_H
#include<vector>
#include<queue>
#include"YachtHand.h"
#include"Dice.h"

class ScoreBoard {
public:
	ScoreBoard() {
		scoreBoard.resize(static_cast<int>(YachtHand::SIZE));
		tempBoard.resize(static_cast<int>(YachtHand::SIZE));
	}
	void checkHand(Dice& d); // 족보 탐색

	std::vector<int> getScoreBoard() { return scoreBoard; } // 스코어보드 가져오기
	int getScoreBoard(int index) { return scoreBoard[index]; }
	bool setScoreBoard(YachtHand yh); // 스코어보드 갱신

	std::vector<int> getTempBoard() { return tempBoard; }
	int getTempBoard(int index) { return tempBoard[index]; }

private:
	std::vector<int> scoreBoard; // 스코어보드
	std::vector<int> tempBoard; // 족보를 담을 예비 스코어보드
	// 족보 계산 함수들
	int check4OfAKind(Dice& dice, std::vector<int>& cnt);
	int checkFullHouse(Dice& dice, std::vector<int>& cnt);	
	int checkStraight(Dice& dice, int n);
	int checkSmallStraight(Dice& dice);
	int checkLargeStraight(Dice& dice);
	int checkYacht(Dice& dice, std::vector<int>& cnt);
};

#endif