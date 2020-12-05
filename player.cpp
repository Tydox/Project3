#include "player.h"
#include <iostream>
#include <cstring>
//#define DEBUG
int Player::indexn = 1;

Player::Player(const char* n) {
#ifndef DEBUG
	if (n)
		setName(n);
	
#else
	
	char name[20];
	_itoa_s(indexn,name,20,10);
	setName(name);
	++indexn;
	#endif

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

const Card* Player::operator-(int num)
{

	if(hand.getNumInDeck() < num)
	{
		if((trash.getNumInDeck() + hand.getNumInDeck())>=num)
		{
			while(trash.getNumInDeck())
			{
				hand.push(trash.pop());
			}
			trash.reset();
			hand.shuffle();
		}
		else
		{
			std::cout <<"Player " << this->getName() <<" Not enough Cards in Hand to play\n";
			const Card* tmp = nullptr;
			return tmp;
		}	
	}

	for (int i=0; i<num;++i)
			trash.push(hand.pop());	
	
	return (trash.getTopDeck());
}

void Player::operator+(Player& rv)
{
	if(*this->getName()==*rv.getName())//check if both names are on the same memory block thus the same player
	{
		//std::cout << "\n\nERROR OPERATOR + : SAME PLAYER,SKIPPING\n\n";
		return;
	}
	
	while (rv.trash.getNumInDeck()>0)
	{
		const Card* tmp = rv.trash.pop();
		*this += *tmp;
	}
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


