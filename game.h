#ifndef GAME
#define GAME

#include "player.h"
#include "database.h"

class game {
public:
	game(player& p, database d);
	void play();
private:
	player m_p;
	database m_d;

	void pick();

	int m_players; //starts at 0, ends at 11
	int m_replacesUsed; //starts at 0, user gets 3 replaces

	bool m_spotsFilled[11]; //starts all false, ends all true ST's are [0], [1]
	bool m_usedCardAlready[129]; //starts all false, if Messi is seen [0] becomes true, allows us to avoid same card showing up twice 

	int randomNewCard(int& positionElem, int ex1, int ex2, int ex3); //positionElem: 0 = ST, 10 = GK etc
	int randomNewCard(int& positionElem);
	int randomNewCard(int& positionElem, int ex1);
	int randomNewCard(int& positionElem, int ex1, int ex2);

	//We want the four random cards to be different positions when possible so some positions will be excluded
	int randomReplacement(int& positionElem); //similar to randomNewCard but finds a card we've never seen before for a filled position

	double avg(); //average ovr of the team, for the end of the game

	void potentiallySwitchPositionOfReplacement(int& pos);
};

#endif
