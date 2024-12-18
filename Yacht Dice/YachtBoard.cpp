#include"YachtBoard.h"

void YachtBoard::printBoard() {
	std::cout << "\t\t" << "Player1\t" << "Player2"<<std::endl;
	std::cout << "Aces\t\t" << m_p1->getSb()[static_cast<int>(YachtHand::ONES)]<<"\t"
		<<m_p2->getSb()[static_cast<int>(YachtHand::ONES)]<<std::endl;

	std::cout << "Deuces\t\t" << m_p1->getSb()[static_cast<int>(YachtHand::TWOS)] << "\t"
		<< m_p2->getSb()[static_cast<int>(YachtHand::TWOS)] << std::endl;

	std::cout << "Threes\t\t" << m_p1->getSb()[static_cast<int>(YachtHand::THREES)] << "\t"
		<< m_p2->getSb()[static_cast<int>(YachtHand::THREES)] << std::endl;

	std::cout << "Fours\t\t" << m_p1->getSb()[static_cast<int>(YachtHand::FOURS)] << "\t"
		<< m_p2->getSb()[static_cast<int>(YachtHand::FOURS)] << std::endl;

	std::cout << "Fives\t\t" << m_p1->getSb()[static_cast<int>(YachtHand::FIVES)] << "\t"
		<< m_p2->getSb()[static_cast<int>(YachtHand::FIVES)] << std::endl;

	std::cout << "Sixes\t\t" << m_p1->getSb()[static_cast<int>(YachtHand::SIXES)] << "\t"
		<< m_p2->getSb()[static_cast<int>(YachtHand::SIXES)] << std::endl;

	std::cout << "Bonus\t\t" << m_p1->getSb()[static_cast<int>(YachtHand::BONUS)] << "\t"
		<< m_p2->getSb()[static_cast<int>(YachtHand::BONUS)] << std::endl;

	std::cout << "4 of a Kind\t" << m_p1->getSb()[static_cast<int>(YachtHand::FOUR_OF_A_KIND)] << "\t"
		<< m_p2->getSb()[static_cast<int>(YachtHand::FOUR_OF_A_KIND)] << std::endl;

	std::cout << "Full House\t" << m_p1->getSb()[static_cast<int>(YachtHand::FULL_HOUSE)] << "\t"
		<< m_p2->getSb()[static_cast<int>(YachtHand::FULL_HOUSE)] << std::endl;

	std::cout << "S. Straight\t" << m_p1->getSb()[static_cast<int>(YachtHand::SMALL_STRAIGHT)] << "\t"
		<< m_p2->getSb()[static_cast<int>(YachtHand::SMALL_STRAIGHT)] << std::endl;

	std::cout << "L. Straight\t" << m_p1->getSb()[static_cast<int>(YachtHand::LARGE_STRAIGHT)] << "\t"
		<< m_p2->getSb()[static_cast<int>(YachtHand::LARGE_STRAIGHT)] << std::endl;

	std::cout << "Yacht\t\t" << m_p1->getSb()[static_cast<int>(YachtHand::YACHT)] << "\t"
		<< m_p2->getSb()[static_cast<int>(YachtHand::YACHT)] << std::endl;

	std::cout << std::endl;
	std::cout << "Dice1\tDice2\tDice3\tDice4\tDice5"<<std::endl;
	std::cout << m_d->getDice(0) << "\t" << m_d->getDice(1) << "\t" << m_d->getDice(2) << "\t"
		<< m_d->getDice(3) << "\t" << m_d->getDice(4) << std::endl;
}