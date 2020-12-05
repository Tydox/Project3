#include "gameEngine.h"
#include <iostream>
#include <ctime>



using namespace std;
int main() {
	srand(std::time(nullptr)); // use current time as seed for random generator

	gameEngine g;
#ifdef FINISHED_OPERATOR1
	g.startGame();
#endif

	return 0;
}