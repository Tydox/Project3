#include "gameEngine.h"
#include <iostream>
#include <ctime>

//#define FINISHED_OPERATOR1
//#define FINISHED_OPERATOR2
//#define FINISHED_OPERATOR3
//#define FINISHED_OPERATOR4

using namespace std;
void main() {
	srand(std::time(nullptr)); // use current time as seed for random generator

	gameEngine g;
#ifdef FINISHED_OPERATOR1
	g.startGame();
#endif


}