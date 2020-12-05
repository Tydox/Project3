#pragma once
#include "CashierStack.h"
#include "Card.h"
#include <iostream>

using namespace std;
class Player {

private:
	char* name;
	CashierStack hand, trash;
	static int indexn;
	
public:
	void setName(const char* name);
	

	const Card* getTopDeck();
	const Card* getTopTrash();
	char* getName()const;


	void shuffleHand();

	Player(const char* name = NULL);
	~Player();

	const Player& operator +=(const Card& cards); 
	const Card* operator -(int num);
	void operator +(Player& rv);

};