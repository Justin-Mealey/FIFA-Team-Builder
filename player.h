#ifndef PLAYER
#define PLAYER

#include "card.h"

class player {
public:
	player(string n);
	player(const player& other);
	~player();
	void display();
	void addCard(int pos, card* player);
	card* getCard(int pos);
	string name(); //returns players name
private:
	string m_name;
	card* team[11];
};

#endif