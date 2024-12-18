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
	void checkHand(Dice d); // ���� Ž��

	std::vector<int> getScoreBoard() { return scoreBoard; } // ���ھ�� ��������
	void setScoreBoard(YachtHand yh); // ���ھ�� ����

private:
	std::vector<int> scoreBoard; // ���ھ��
	std::vector<int> tempBoard; // ������ ���� ���� ���ھ��
	Dice dice; // �ֻ��� ��

	// ���� ��� �Լ���
	int check4OfAKind();
	int checkFullHouse(std::vector<int>& cnt);
	int checkStraight(int n);
	int checkSmallStraight();
	int checkLargeStraight();
	int checkYacht(std::vector<int>& cnt);
};

#endif