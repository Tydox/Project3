
#include "player.h"
#include <iostream>
#include <cstring>


Player::Player(const char* n) {

	if (n)
		setName(n);


}

Player::~Player()
{
#ifdef DEBUG
	cout << "\n Kill Player: " << name;
#endif // DEBUG
	delete[] name;
}

const Player& Player::operator+=(const Card& cards)
{
	hand.push(&cards);
	return *this;
}

void Player::setName(const char* n) {
	int size = strlen(n) + 1;
	name = new char[size];
	strcpy_s(name, size, n);
}




const Card* Player::getTopTrash() {
	return trash.getTopDeck();
}



char* Player::getName() const
{
	return name;
}

void Player::shuffleHand()
{
	hand.shuffle();
}


