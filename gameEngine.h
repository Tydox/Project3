#ifndef _GAMEENGINE
#define _GAMEENGINE



#include "card.h"
#include "player.h"

#define NO_OF_DECK 1
#define NUM_IN_SERIAL 13
class gameEngine {

private:
	Card Cards[NO_OF_DECK * NUM_IN_SERIAL * 4];
	
	class playerMng {

		private:
		Player** players;
		int howManyPlayrs;

		friend class gameEngine;
		public:
		
	}players;

	
	
public:
	gameEngine();
	~gameEngine();

	void buildCards();
	void buildCards(int startIdx, char sign);
	void setPlayers();
	bool extructPlayer(Player* looser);
	bool turn();
	void startGame();
	void moveCardsTrashCardsToWinner(Player* winner);
};


#endif
