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
	void checkHand(Dice& d); // ���� Ž��

	std::vector<int> getScoreBoard() { return scoreBoard; } // ���ھ�� ��������
	int getScoreBoard(int index) { return scoreBoard[index]; }
	bool setScoreBoard(YachtHand yh); // ���ھ�� ����

	std::vector<int> getTempBoard() { return tempBoard; }
	int getTempBoard(int index) { return tempBoard[index]; }

private:
	std::vector<int> scoreBoard; // ���ھ��
	std::vector<int> tempBoard; // ������ ���� ���� ���ھ��
	// ���� ��� �Լ���
	int check4OfAKind(Dice& dice, std::vector<int>& cnt);
	int checkFullHouse(Dice& dice, std::vector<int>& cnt);	
	int checkStraight(Dice& dice, int n);
	int checkSmallStraight(Dice& dice);
	int checkLargeStraight(Dice& dice);
	int checkYacht(Dice& dice, std::vector<int>& cnt);
};

#endif