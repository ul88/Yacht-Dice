#include"Deserialization.h"
void Deserialization::output(YachtBoard& board, Player& player1, Player& player2, 
	Dice& d,type& t) {
	board.setTurn(t.turn);

	//player1 流纺拳
	std::vector<int> v1(sizeof(t.sb1)/sizeof(int));
	for (int i = 0;i < v1.size();i++) {
		v1[i] = t.sb1[i];
	}
	
	std::vector<int> v2(sizeof(t.tb1)/sizeof(int));
	for (int i = 0;i < v2.size();i++) {
		v2[i] = t.tb1[i];
	}

	player1.setScoreBoard(v1, v2);

	//player2 开流纺拳
	for (int i = 0;i < v1.size();i++) {
		v1[i] = t.sb2[i];
	}

	for (int i = 0;i < v2.size();i++) {
		v2[i] = t.tb2[i];
	}
	player2.setScoreBoard(v1, v2);
	
	//dice 开流纺拳
	std::vector<int> v3(sizeof(t.d) / sizeof(int));
	for (int i = 0;i < v3.size();i++) {
		v3[i] = t.d[i];
	}
	d.setDice(v3);

	//reroll 开流纺拳
	std::vector<bool> v4(5);
	for (int i = 0;i < 5;i++) {
		v4[i] = t.sd[i];
		std::cout << "开流纺拳 select dice" << " " << t.sd[i] << "\n";
	}
	d.setReroll(v4);

	d.setRerollCount(t.rerollCount);
}