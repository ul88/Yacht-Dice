#include"ScoreBoard.h"
#include<iostream>
bool ScoreBoard::setScoreBoard(YachtHand yh) { // 스코어 보드 갱신
	if (scoreBoard[static_cast<int>(yh)] == 0) {
		scoreBoard[static_cast<int>(yh)] = tempBoard[static_cast<int>(yh)];
		score += scoreBoard[static_cast<int>(yh)];
		return true;
	}
	return false;
}

void ScoreBoard::checkHand(Dice& dice) { // 족보 탐색
	std::vector<int> cnt(6, 0);

	for (auto iter : dice.getDice()) {
		cnt[iter - 1]++;
	}

	tempBoard[static_cast<int>(YachtHand::ONES)] = cnt[0]*1;
	tempBoard[static_cast<int>(YachtHand::TWOS)] = cnt[1]*2;
	tempBoard[static_cast<int>(YachtHand::THREES)] = cnt[2]*3;
	tempBoard[static_cast<int>(YachtHand::FOURS)] = cnt[3]*4;
	tempBoard[static_cast<int>(YachtHand::FIVES)] = cnt[4]*5;
	tempBoard[static_cast<int>(YachtHand::SIXES)] = cnt[5]*6;
	tempBoard[static_cast<int>(YachtHand::CHOICE)] = dice.getSum();
	tempBoard[static_cast<int>(YachtHand::FOUR_OF_A_KIND)] = check4OfAKind(dice, cnt);
	tempBoard[static_cast<int>(YachtHand::FULL_HOUSE)] = checkFullHouse(dice, cnt);
	tempBoard[static_cast<int>(YachtHand::SMALL_STRAIGHT)] = checkSmallStraight(dice);
	tempBoard[static_cast<int>(YachtHand::LARGE_STRAIGHT)] = checkLargeStraight(dice);
	tempBoard[static_cast<int>(YachtHand::YACHT)] = checkYacht(dice, cnt);
}

int ScoreBoard::check4OfAKind(Dice& dice, std::vector<int>& cnt) {
	for (int i = 0;i < cnt.size();i++) {
		if (cnt[i] >= 4) return dice.getSum();
	}
	return 0;
}

int ScoreBoard::checkFullHouse(Dice& dice, std::vector<int>& cnt) {
	int two = -1, three = -1, five = -1;
	for (int i = 0;i < cnt.size();i++) {
		if (cnt[i] == 2) two = i;
		if (cnt[i] == 3) three = i;
		if (cnt[i] == 5) five = i;
	}

	if ((two >= 0 && three >= 0) || five >= 0) {
		return dice.getSum();
	}

	return 0;
}

int ScoreBoard::checkStraight(Dice& dice, int n) {
	int ret = 0;
	std::vector<bool> visit(7, false);
	std::queue<int> q;
	q.push(n);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (visit[now]) continue;
		visit[now] = true;
		ret++;
		for (int i = 0;i < dice.getDice().size();i++) {
			if (dice.getDice(i) == now + 1) q.push(dice.getDice(i));
		}
	}
	return ret;
}

int ScoreBoard::checkSmallStraight(Dice& dice) {
	int ret = std::max(checkStraight(dice, 0), checkStraight(dice, 1));
	if (ret >= 5) return 15;
	return 0;
}

int ScoreBoard::checkLargeStraight(Dice& dice) {
	int ret = checkStraight(dice, 1);
	if (ret == 6) return 30;
	return 0;
}

int ScoreBoard::checkYacht(Dice& dice, std::vector<int>& cnt) {
	for (int i = 0;i < cnt.size();i++) {
		if (cnt[i] == 5) return 50;
	}
	return 0;
}