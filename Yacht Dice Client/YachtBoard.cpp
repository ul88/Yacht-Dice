#include"YachtBoard.h"

void YachtBoard::setTurn(int turn) {
	m_turn = turn;
}

void YachtBoard::printBoard() {
	std::cout << "현재 " << (m_turn % 2 == 0 ? "Player1" : "Player2") 
		<< " 차례 남은 턴: " << m_turn / 2 + 1
		<< "\t" << "Player1\t" << "Player2" << std::endl;
	if (m_turn % 2 == 0) {
		if (m_p1->getScoreBoard(YachtHand::ONES) != 0) {
			std::cout << "Aces\t\t\t\t" 
				<< m_p1->getScoreBoard(YachtHand::ONES) << "\t"
				<< m_p2->getScoreBoard(YachtHand::ONES) << std::endl;
		}
		else {
			std::cout << "Aces\t\t\t\t*"
				<< m_p1->getTempBoard(YachtHand::ONES) << "\t"
				<< m_p2->getScoreBoard(YachtHand::ONES) << std::endl;
		}

		if (m_p1->getScoreBoard(YachtHand::TWOS) != 0) {
			std::cout << "Deuces\t\t\t\t"
				<< m_p1->getScoreBoard(YachtHand::TWOS) << "\t"
				<< m_p2->getScoreBoard(YachtHand::TWOS) << std::endl;
		}
		else {
			std::cout << "Deuces\t\t\t\t*"
				<< m_p1->getTempBoard(YachtHand::TWOS) << "\t"
				<< m_p2->getScoreBoard(YachtHand::TWOS) << std::endl;
		}

		if (m_p1->getScoreBoard(YachtHand::THREES) != 0) {
			std::cout << "Threes\t\t\t\t"
				<< m_p1->getScoreBoard(YachtHand::THREES) << "\t"
				<< m_p2->getScoreBoard(YachtHand::THREES) << std::endl;
		}
		else {
			std::cout << "Threes\t\t\t\t*"
				<< m_p1->getTempBoard(YachtHand::THREES) << "\t"
				<< m_p2->getScoreBoard(YachtHand::THREES) << std::endl;
		}

		if (m_p1->getScoreBoard(YachtHand::FOURS) != 0) {
			std::cout << "Fours\t\t\t\t"
				<< m_p1->getScoreBoard(YachtHand::FOURS) << "\t"
				<< m_p2->getScoreBoard(YachtHand::FOURS) << std::endl;
		}
		else {
			std::cout << "Fours\t\t\t\t*"
				<< m_p1->getTempBoard(YachtHand::FOURS) << "\t"
				<< m_p2->getScoreBoard(YachtHand::FOURS) << std::endl;
		}
		
		if (m_p1->getScoreBoard(YachtHand::FIVES) != 0) {
			std::cout << "Fives\t\t\t\t"
				<< m_p1->getScoreBoard(YachtHand::FIVES) << "\t"
				<< m_p2->getScoreBoard(YachtHand::FIVES) << std::endl;
		}
		else {
			std::cout << "Fives\t\t\t\t*"
				<< m_p1->getTempBoard(YachtHand::FIVES) << "\t"
				<< m_p2->getScoreBoard(YachtHand::FIVES) << std::endl;
		}

		if (m_p1->getScoreBoard(YachtHand::SIXES) != 0) {
			std::cout << "Sixes\t\t\t\t"
				<< m_p1->getScoreBoard(YachtHand::SIXES) << "\t"
				<< m_p2->getScoreBoard(YachtHand::SIXES) << std::endl;
		}
		else {
			std::cout << "Sixes\t\t\t\t*"
				<< m_p1->getTempBoard(YachtHand::SIXES) << "\t"
				<< m_p2->getScoreBoard(YachtHand::SIXES) << std::endl;
		}

		if (m_p1->getScoreBoard(YachtHand::BONUS) != 0) {
			std::cout << "Bonus\t\t\t\t"
				<< m_p1->getScoreBoard(YachtHand::BONUS) << "\t"
				<< m_p2->getScoreBoard(YachtHand::BONUS) << std::endl;
		}
		else {
			std::cout << "Bonus\t\t\t\t*"
				<< m_p1->getTempBoard(YachtHand::BONUS) << "\t"
				<< m_p2->getScoreBoard(YachtHand::BONUS) << std::endl;
		}

		if (m_p1->getScoreBoard(YachtHand::CHOICE) != 0) {
			std::cout << "Choice\t\t\t\t"
				<< m_p1->getScoreBoard(YachtHand::CHOICE) << "\t"
				<< m_p2->getScoreBoard(YachtHand::CHOICE) << std::endl;
		}
		else {
			std::cout << "Choice\t\t\t\t*"
				<< m_p1->getTempBoard(YachtHand::CHOICE) << "\t"
				<< m_p2->getScoreBoard(YachtHand::CHOICE) << std::endl;
		}

		if (m_p1->getScoreBoard(YachtHand::FOUR_OF_A_KIND) != 0) {
			std::cout << "4 of a Kind\t\t\t"
				<< m_p1->getScoreBoard(YachtHand::FOUR_OF_A_KIND) << "\t"
				<< m_p2->getScoreBoard(YachtHand::FOUR_OF_A_KIND) << std::endl;
		}
		else {
			std::cout << "4 of a Kind\t\t\t*"
				<< m_p1->getTempBoard(YachtHand::FOUR_OF_A_KIND) << "\t"
				<< m_p2->getScoreBoard(YachtHand::FOUR_OF_A_KIND) << std::endl;
		}

		if (m_p1->getScoreBoard(YachtHand::FULL_HOUSE) != 0) {
			std::cout << "Full House\t\t\t"
				<< m_p1->getScoreBoard(YachtHand::FULL_HOUSE) << "\t"
				<< m_p2->getScoreBoard(YachtHand::FULL_HOUSE) << std::endl;
		}
		else {
			std::cout << "Full House\t\t\t*"
				<< m_p1->getTempBoard(YachtHand::FULL_HOUSE) << "\t"
				<< m_p2->getScoreBoard(YachtHand::FULL_HOUSE) << std::endl;
		}

		if (m_p1->getScoreBoard(YachtHand::SMALL_STRAIGHT) != 0) {
			std::cout << "S. Straight\t\t\t"
				<< m_p1->getScoreBoard(YachtHand::SMALL_STRAIGHT) << "\t"
				<< m_p2->getScoreBoard(YachtHand::SMALL_STRAIGHT) << std::endl;
		}
		else {
			std::cout << "S. Straight\t\t\t*"
				<< m_p1->getTempBoard(YachtHand::SMALL_STRAIGHT) << "\t"
				<< m_p2->getScoreBoard(YachtHand::SMALL_STRAIGHT) << std::endl;
		}

		if (m_p1->getScoreBoard(YachtHand::LARGE_STRAIGHT) != 0) {
			std::cout << "L. Straight\t\t\t"
				<< m_p1->getScoreBoard(YachtHand::LARGE_STRAIGHT) << "\t"
				<< m_p2->getScoreBoard(YachtHand::LARGE_STRAIGHT) << std::endl;
		}
		else {
			std::cout << "L. Straight\t\t\t*"
				<< m_p1->getTempBoard(YachtHand::LARGE_STRAIGHT) << "\t"
				<< m_p2->getScoreBoard(YachtHand::LARGE_STRAIGHT) << std::endl;
		}

		if (m_p1->getScoreBoard(YachtHand::YACHT) != 0) {
			std::cout << "Yacht\t\t\t\t"
				<< m_p1->getScoreBoard(YachtHand::YACHT) << "\t"
				<< m_p2->getScoreBoard(YachtHand::YACHT) << std::endl;
		}
		else {
			std::cout << "Yacht\t\t\t\t*"
				<< m_p1->getTempBoard(YachtHand::YACHT) << "\t"
				<< m_p2->getScoreBoard(YachtHand::YACHT) << std::endl;
		}
	}
	else {
		if (m_p2->getScoreBoard(YachtHand::ONES) != 0) {
			std::cout << "Aces\t\t\t\t"
				<< m_p1->getScoreBoard(YachtHand::ONES) << "\t"
				<< m_p2->getScoreBoard(YachtHand::ONES) << std::endl;
		}
		else {
			std::cout << "Aces\t\t\t\t"
				<< m_p1->getScoreBoard(YachtHand::ONES) << "\t"
				<< "*" << m_p2->getTempBoard(YachtHand::ONES) << std::endl;
		}

		if (m_p2->getScoreBoard(YachtHand::TWOS) != 0) {
			std::cout << "Deuces\t\t\t\t"
				<< m_p1->getScoreBoard(YachtHand::TWOS) << "\t"
				<< m_p2->getScoreBoard(YachtHand::TWOS) << std::endl;
		}
		else {
			std::cout << "Deuces\t\t\t\t"
				<< m_p1->getScoreBoard(YachtHand::TWOS) << "\t"
				<< "*" << m_p2->getTempBoard(YachtHand::TWOS) << std::endl;
		}

		if (m_p2->getScoreBoard(YachtHand::THREES) != 0) {
			std::cout << "Threes\t\t\t\t"
				<< m_p1->getScoreBoard(YachtHand::THREES) << "\t"
				<< m_p2->getScoreBoard(YachtHand::THREES) << std::endl;
		}
		else {
			std::cout << "Threes\t\t\t\t"
				<< m_p1->getScoreBoard(YachtHand::THREES) << "\t"
				<< "*" << m_p2->getTempBoard(YachtHand::THREES) << std::endl;
		}

		if (m_p2->getScoreBoard(YachtHand::FOURS) != 0) {
			std::cout << "Fours\t\t\t\t"
				<< m_p1->getScoreBoard(YachtHand::FOURS) << "\t"
				<< m_p2->getScoreBoard(YachtHand::FOURS) << std::endl;
		}
		else {
			std::cout << "Fours\t\t\t\t"
				<< m_p1->getScoreBoard(YachtHand::FOURS) << "\t"
				<< "*" << m_p2->getTempBoard(YachtHand::FOURS) << std::endl;
		}
		if (m_p2->getScoreBoard(YachtHand::FIVES) != 0) {
			std::cout << "Fives\t\t\t\t"
				<< m_p1->getScoreBoard(YachtHand::FIVES) << "\t"
				<< m_p2->getScoreBoard(YachtHand::FIVES) << std::endl;
		}
		else {
			std::cout << "Fives\t\t\t\t"
				<< m_p1->getScoreBoard(YachtHand::FIVES) << "\t"
				<< "*" << m_p2->getTempBoard(YachtHand::FIVES) << std::endl;
		}
		if (m_p2->getScoreBoard(YachtHand::SIXES) != 0) {
			std::cout << "Sixes\t\t\t\t"
				<< m_p1->getScoreBoard(YachtHand::SIXES) << "\t"
				<< m_p2->getScoreBoard(YachtHand::SIXES) << std::endl;
		}
		else {
			std::cout << "Sixes\t\t\t\t"
				<< m_p1->getScoreBoard(YachtHand::SIXES) << "\t"
				<< "*" << m_p2->getTempBoard(YachtHand::SIXES) << std::endl;
		}
		if (m_p2->getScoreBoard(YachtHand::BONUS) != 0) {
			std::cout << "Bonus\t\t\t\t"
				<< m_p1->getScoreBoard(YachtHand::BONUS) << "\t"
				<< m_p2->getScoreBoard(YachtHand::BONUS) << std::endl;
		}
		else {
			std::cout << "Bonus\t\t\t\t"
				<< m_p1->getScoreBoard(YachtHand::BONUS) << "\t"
				<< "*" << m_p2->getTempBoard(YachtHand::BONUS) << std::endl;
		}
		if (m_p2->getScoreBoard(YachtHand::CHOICE) != 0) {
			std::cout << "Choice\t\t\t\t"
				<< m_p1->getScoreBoard(YachtHand::CHOICE) << "\t"
				<< m_p2->getScoreBoard(YachtHand::CHOICE) << std::endl;
		}
		else {
			std::cout << "Choice\t\t\t\t"
				<< m_p1->getScoreBoard(YachtHand::CHOICE) << "\t"
				<< "*" << m_p2->getTempBoard(YachtHand::CHOICE) << std::endl;
		}
		if (m_p2->getScoreBoard(YachtHand::FOUR_OF_A_KIND) != 0) {
			std::cout << "4 of a Kind\t\t\t"
				<< m_p1->getScoreBoard(YachtHand::FOUR_OF_A_KIND) << "\t"
				<< m_p2->getScoreBoard(YachtHand::FOUR_OF_A_KIND) << std::endl;
		}
		else {
			std::cout << "4 of a Kind\t\t\t"
				<< m_p1->getScoreBoard(YachtHand::FOUR_OF_A_KIND) << "\t"
				<< "*" << m_p2->getTempBoard(YachtHand::FOUR_OF_A_KIND) << std::endl;
		}
		if (m_p2->getScoreBoard(YachtHand::FULL_HOUSE) != 0) {
			std::cout << "Full House\t\t\t"
				<< m_p1->getScoreBoard(YachtHand::FULL_HOUSE) << "\t"
				<< m_p2->getScoreBoard(YachtHand::FULL_HOUSE) << std::endl;
		}
		else {
			std::cout << "Full House\t\t\t"
				<< m_p1->getScoreBoard(YachtHand::FULL_HOUSE) << "\t"
				<< "*" << m_p2->getTempBoard(YachtHand::FULL_HOUSE) << std::endl;
		}
		if (m_p2->getScoreBoard(YachtHand::SMALL_STRAIGHT) != 0) {
			std::cout << "S. Straight\t\t\t"
				<< m_p1->getScoreBoard(YachtHand::SMALL_STRAIGHT) << "\t"
				<< m_p2->getScoreBoard(YachtHand::SMALL_STRAIGHT) << std::endl;
		}
		else {
			std::cout << "S. Straight\t\t\t"
				<< m_p1->getScoreBoard(YachtHand::SMALL_STRAIGHT) << "\t"
				<< "*" << m_p2->getTempBoard(YachtHand::SMALL_STRAIGHT) << std::endl;
		}
		if (m_p2->getScoreBoard(YachtHand::LARGE_STRAIGHT) != 0) {
			std::cout << "L. Straight\t\t\t"
				<< m_p1->getScoreBoard(YachtHand::LARGE_STRAIGHT) << "\t"
				<< m_p2->getScoreBoard(YachtHand::LARGE_STRAIGHT) << std::endl;
		}
		else {
			std::cout << "L. Straight\t\t\t"
				<< m_p1->getScoreBoard(YachtHand::LARGE_STRAIGHT) << "\t"
				<< "*" << m_p2->getTempBoard(YachtHand::LARGE_STRAIGHT) << std::endl;
		}
		if (m_p2->getScoreBoard(YachtHand::YACHT) != 0) {
			std::cout << "Yacht\t\t\t\t"
				<< m_p1->getScoreBoard(YachtHand::YACHT) << "\t"
				<< m_p2->getScoreBoard(YachtHand::YACHT) << std::endl;
		}
		else {
			std::cout << "Yacht\t\t\t\t"
				<< m_p1->getScoreBoard(YachtHand::YACHT) << "\t"
				<< "*" << m_p2->getTempBoard(YachtHand::YACHT) << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "Dice1\tDice2\tDice3\tDice4\tDice5" << std::endl;
	std::cout << m_d->getDice(0) << "\t" << m_d->getDice(1) << "\t" << m_d->getDice(2) << "\t"
		<< m_d->getDice(3) << "\t" << m_d->getDice(4) << std::endl;
	std::cout << m_d->getReroll(0) << "\t" << m_d->getReroll(1) << "\t" << m_d->getReroll(2)
		<< "\t" << m_d->getReroll(3) << "\t" << m_d->getReroll(4) << std::endl;
}