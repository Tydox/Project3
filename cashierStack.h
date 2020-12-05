#pragma once
#include "Card.h"
#include <iostream>


class CashierStack {

private:
	class stackItem
	{
		const Card* card;
		stackItem* next;
		friend CashierStack;
	}*head;
	int numInDeck;

	friend class Player;
	
public:

	CashierStack();
	~CashierStack();
	int getNumInDeck()const;
	const Card* getTopDeck()const;

	const Card* pop();

	void push(const Card* c);

	void shuffle();
	void reset();


	void shuffleNitem(int n);




};
