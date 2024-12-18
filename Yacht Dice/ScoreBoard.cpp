#include"ScoreBoard.h"

void ScoreBoard::setScoreBoard(YachtHand yh) { // 스코어 보드 갱신
	if (scoreBoard[static_cast<int>(yh)] == 0) {
		scoreBoard[static_cast<int>(yh)] = tempBoard[static_cast<int>(yh)];
	}
}

void ScoreBoard::checkHand(Dice d) { // 족보 탐색
	dice = d;
	std::vector<int> cnt(6, 0);

	for (auto iter : dice.getDice()) {
		cnt[iter - 1]++;
	}

	tempBoard[static_cast<int>(YachtHand::ONES)] = cnt[0];
	tempBoard[static_cast<int>(YachtHand::TWOS)] = cnt[1];
	tempBoard[static_cast<int>(YachtHand::THREES)] = cnt[2];
	tempBoard[static_cast<int>(YachtHand::FOURS)] = cnt[3];
	tempBoard[static_cast<int>(YachtHand::FIVES)] = cnt[4];
	tempBoard[static_cast<int>(YachtHand::SIXES)] = cnt[5];
	tempBoard[static_cast<int>(YachtHand::CHOICE)] = cnt[0] + cnt[1] + cnt[2] + cnt[3] + cnt[4] + cnt[5];
	tempBoard[static_cast<int>(YachtHand::FOUR_OF_A_KIND)] = check4OfAKind();
	tempBoard[static_cast<int>(YachtHand::FULL_HOUSE)] = checkFullHouse(cnt);
	tempBoard[static_cast<int>(YachtHand::SMALL_STRAIGHT)] = checkSmallStraight();
	tempBoard[static_cast<int>(YachtHand::LARGE_STRAIGHT)] = checkLargeStraight();
	tempBoard[static_cast<int>(YachtHand::YACHT)] = checkYacht(cnt);
}

int ScoreBoard::check4OfAKind() {
	for (int i = 0;i < dice.getDice().size();i++) {
		int cnt = 0;
		for (int j = 0;j < dice.getDice().size();j++) {
			if (i == j) continue;
			if (dice.getDice(i) == dice.getDice(j)) cnt++;
		}

		if (cnt == 4) {
			return dice.getSum();
		}
	}
	return 0;
}

int ScoreBoard::checkFullHouse(std::vector<int>& cnt) {
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

int ScoreBoard::checkStraight(int n) {
	for (auto iter : dice.getDice()) {
		if (iter == n + 1) {
			return checkStraight(iter) + 1;
		}
	}
}

int ScoreBoard::checkSmallStraight() {
	int cnt = std::max(checkStraight(0), checkStraight(1));
	if (cnt >= 4) return 15;
	return 0;
}

int ScoreBoard::checkLargeStraight() {
	int cnt = checkStraight(0);
	if (cnt == 5) return 30;
	return 0;
}

int ScoreBoard::checkYacht(std::vector<int>& cnt) {
	for (int i = 0;i < cnt.size();i++) {
		if (cnt[i] == 5) return dice.getSum();
	}
	return 0;
}