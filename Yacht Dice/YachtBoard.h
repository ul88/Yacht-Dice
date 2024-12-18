#pragma once
#ifndef YACHTMAP_H
#define YACHTMAP_H
#include<iostream>
#include"Player.h"

class YachtBoard {
public:
	YachtBoard(Player* p1, Player* p2, Dice* d) : m_p1(p1), m_p2(p2), m_d(d) {}

	void printBoard();
private:
	Player* m_p1;
	Player* m_p2;
	Dice* m_d;
};

#endif