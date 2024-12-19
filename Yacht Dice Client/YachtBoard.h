#pragma once
#ifndef YACHTMAP_H
#define YACHTMAP_H
#include<iostream>
#include<string>
#include"Player.h"
#include"YachtHand.h"
#include"Dice.h"

class YachtBoard {
public:
	YachtBoard(Player* p1, Player* p2, Dice* d) : 
		m_p1(p1), m_p2(p2), m_d(d), m_turn(0) {}

	int getTurn() { return m_turn; }
	void setTurn(int turn);

	void printBoard();
private:
	Player* m_p1;
	Player* m_p2;
	Dice* m_d;
	int m_turn;
};

#endif