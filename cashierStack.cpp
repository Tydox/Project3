#include "CashierStack.h"

#include <iostream>
using namespace std;

CashierStack::CashierStack() {
	head = nullptr;
	numInDeck = 0;
}

CashierStack::~CashierStack()
{

	while (head) {
		stackItem* tmp = head;
		head = head->next;
		delete tmp;
	}
	numInDeck = 0;
}

int CashierStack::getNumInDeck() const
{
	return numInDeck;
}

const Card* CashierStack::getTopDeck() const
{
	return head->card;
}

const Card* CashierStack::pop() {
	stackItem* tmp = head;
	if (head) {
		const Card* res = head->card;
		head = head->next;
		delete tmp;
		numInDeck--;
		return res;

	}
	return nullptr;
}

void CashierStack::push(const Card* c) {
	stackItem* newItem = new stackItem;
	newItem->card = c;
	newItem->next = head;
	head = newItem;
	numInDeck++;
}

void CashierStack::shuffle() {

	for (int i = 0; i < 200; i++) {
		int random_variable = std::rand();
		shuffleNitem(rand() % (numInDeck));
	}

}

void CashierStack::reset()
{
	head = nullptr;
	numInDeck = 0;
}

void CashierStack::shuffleNitem(int n)
{
	CashierStack tmp;//will be destruct at the end of this block - will call destructor
	while (n > 1 && head) {
		tmp.push(pop());
		n--;
	}

	const Card* c = pop();


	while (tmp.head) {
		push(tmp.pop());
	}
	push(c);
}
