#ifndef DATABASE
#define DATABASE

#include "card.h"
#include <vector>

class database {
public:
	database();
	~database();
	database(const database& other);
	void display4(int a, int b, int c, int d);
	void display2(int a, int b);
	card* getCard(int elem);
private:
	vector<card*> m_cards;
};

#endif
