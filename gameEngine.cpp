#include "gameEngine.h"
#include <iostream>
#define DEBUG_PLAYER_NO 4
//#define DEBUG
using namespace std;


void gameEngine::buildCards() {


	for (int i = 0; i < NO_OF_DECK * NUM_IN_SERIAL * 4; i += NUM_IN_SERIAL) {
		buildCards(i, 'S');
		i += NUM_IN_SERIAL;
		buildCards(i, 'C');
		i += NUM_IN_SERIAL;
		buildCards(i, 'D');
		i += NUM_IN_SERIAL;
		buildCards(i, 'H');
	}


	for (int cardIdx = 0; cardIdx < NO_OF_DECK * NUM_IN_SERIAL * 4;) {
		for (int playerIdx = 0; playerIdx < players.howManyPlayrs && cardIdx < NO_OF_DECK * NUM_IN_SERIAL * 4; playerIdx++)
			*(players.players[playerIdx]) += (Cards[cardIdx++]);// Students - To do//OPERATOR1
	}

	for (int playerIdx = 0; playerIdx < players.howManyPlayrs; playerIdx++)
		players.players[playerIdx]->shuffleHand();

};
void gameEngine::buildCards(int startIdx, char sign) {


	for (char i = 1; i <= NUM_IN_SERIAL; startIdx++, i++) {
		Cards[startIdx].setCard(sign, i);
	}

}
bool gameEngine::turn() {
	bool play = true, isFirst = true;

	/// Rounds of game : play until one player is higher than all:
	int maxCount, noOfParicipants = players.howManyPlayrs;
	Player** paticipants = players.players;
	playerMng res;
#ifdef FINISHED_OPERATOR4
	do {
#endif // !FINISHED_OPERATOR4
		/*set res -> array of players with the maximum card - could be more than one */
		res.players = new Player * [noOfParicipants];

		/*By default No maximum players */
		res.howManyPlayrs = 0;
		res.players[0] = NULL;

		/*set max to zero value */
		Card min;
		min.setCard('S', 0);
		const Card* max = &min;
		const Card* tmp;

		/*LOOP: extruct cards from every user deck (extruct one in case first draw or 3 cards otherwise)- check if extructed card is max */
		for (int no = 0; no < noOfParicipants; no++) {

			if (!isFirst)
				tmp = (*(paticipants[no])) - 3;// Students - To do//OPERATOR2
			else
				tmp = (*(paticipants[no])) - 1;// Students - To do//OPERATOR2

			if (!tmp) {
				play = extructPlayer(paticipants[no]);
				if (isFirst)
				{
					paticipants = players.players;
					noOfParicipants--;
					no--;
				}
				if (!play) return false;
			}
#ifdef FINISHED_OPERATOR2
			else {
				cout << "\nPlayer " << (paticipants[no])->getName() << " Card: ";
				tmp->printCard();

				if (*tmp > * max) {// Students - To do// OPERATOR3
					max = tmp;
					res.howManyPlayrs = 1;
					res.players[0] = paticipants[no];
				}
#ifdef FINISHED_OPERATOR3
				else if (*tmp == *max) {// Students - To do// OPERATOR4
					res.players[res.howManyPlayrs++] = paticipants[no];
				}
#endif // !FINISHED_OPERATOR3

			}
#endif // !FINISHED_OPERATOR2


		}
#ifdef FINISHED_OPERATOR4
		/*delete unneccerary memory*/
		if (!isFirst) {
			delete[] paticipants;
		}
		/*set next round to the maximum card players holders*/
		paticipants = res.players;
		noOfParicipants = res.howManyPlayrs;
		isFirst = false;
		if (noOfParicipants > 1) cout << "\nLets battle!:";
	} while (noOfParicipants > 1);//contiue until there is only one winner

	/*Move cards from loosers trash to winners hand: */
	moveCardsTrashCardsToWinner(paticipants[0]);

	if (players.howManyPlayrs == 1)
		return false;

#else
#ifdef FINISHED_OPERATOR2
		printf("\nMax Card is ");
		max->printCard();
#endif // !FINISHED_OPERATOR3

#endif // !FINISHED_OPERATOR4
		return true;
}
	void gameEngine::startGame() {
		bool play = true;
		int round = 1;
#ifdef FINISHED_OPERATOR1
		play = turn();
#endif
#ifdef FINISHED_OPERATOR4
		while (play) {
			cout << "\nRound No " << round << endl;
			play = turn();
			round++;

		}
		cout << "\nPlayer " << players.players[0]->getName() << " WINS!****" << endl;
#endif

	}

	void gameEngine::moveCardsTrashCardsToWinner(Player* winner)
	{
		cout << "\n***Player " << winner->getName() << " get all cards**";
		for (int playerIdx = 0; playerIdx < players.howManyPlayrs; playerIdx++) {

			*winner + *(players.players[playerIdx]);// Students - To do//  OPERATOR2

		}

	}






	void gameEngine::setPlayers() {

#ifndef DEBUG
		char tmpName[20] = { 0 };
		cout << "\nhow many players? : ";
		cin >> players.howManyPlayrs;
#else
		players.howManyPlayrs = DEBUG_PLAYER_NO;
#endif // !DEBUG
		players.players = new Player * [players.howManyPlayrs];

		for (int i = 0; i < players.howManyPlayrs; i++) {

#ifndef DEBUG
			cout << "type player " << i + 1 << " name :";
			cin >> tmpName;

			players.players[i] = new Player(tmpName);
#else
			players.players[i] = new Player();
#endif // !DEBUG

		}

	}

	bool gameEngine::extructPlayer(Player* looser)
	{
		cout << "\nPlayer " << looser->getName() << " Looses!" << endl;

		Player** newArr = new Player * [players.howManyPlayrs - 1];
		for (int i = 0, j = 0; i < players.howManyPlayrs; i++) {
			if (players.players[i] != looser)
			{
				newArr[j++] = players.players[i];
			}
			else players.players[i];
		}
		delete[] players.players;
		players.players = newArr;
		players.howManyPlayrs--;
		if (players.howManyPlayrs == 1) return false;
		return true;
	}



	gameEngine::gameEngine() {
		players.howManyPlayrs = 0;
		players.players = NULL;
		setPlayers();
		buildCards();

	}

	gameEngine::~gameEngine()
	{
		for (int i = 0; i < players.howManyPlayrs; i++) {
			delete players.players[i];
		}
		delete[] players.players;
	}
