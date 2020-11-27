#pragma once
#include "CashierStack.h"
#include "Card.h"
#include <iostream>
using namespace std;
class Player {

private:
	char* name;
	CashierStack hand, trash;

public:
	void setName(const char* name);


	const Card* getTopDeck();
	const Card* getTopTrash();
	char* getName()const;


	void shuffleHand();

	Player(const char* name = NULL);
	~Player();




};
