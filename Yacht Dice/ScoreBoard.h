#pragma once
#ifndef SCOREBOARD_H
#define SCOREBOARD_H
#include<vector>
#include"Dice.h"

enum class YachtHand {
	ONES = 0,
	TWOS,
	THREES,
	FOURS,
	FIVES,
	SIXES,
	CHOICE,
	FOUR_OF_A_KIND,
	FULL_HOUSE,
	SMALL_STRAIGHT,
	LARGE_STRAIGHT,
	YACHT,
	BONUS,
	SIZE
};

class ScoreBoard {
public:
	ScoreBoard() {
		scoreBoard.resize(static_cast<int>(YachtHand::SIZE));
		tempBoard.resize(static_cast<int>(YachtHand::SIZE));
	}
	void checkHand(Dice d); // 족보 탐색

	std::vector<int> getScoreBoard() { return scoreBoard; } // 스코어보드 가져오기
	void setScoreBoard(YachtHand yh); // 스코어보드 갱신

private:
	std::vector<int> scoreBoard; // 스코어보드
	std::vector<int> tempBoard; // 족보를 담을 예비 스코어보드
	Dice dice; // 주사위 값

	// 족보 계산 함수들
	int check4OfAKind();
	int checkFullHouse(std::vector<int>& cnt);
	int checkStraight(int n);
	int checkSmallStraight();
	int checkLargeStraight();
	int checkYacht(std::vector<int>& cnt);
};

#endif