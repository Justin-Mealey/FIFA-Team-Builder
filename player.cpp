#include "player.h"
player::~player() {
	for (int i = 0; i < 11; i++) {
		delete team[i];
	}
}
player::player(const player& other) {
	m_name = other.m_name;
	team[0] = new card(other.team[0]);
	team[1] = new card(other.team[1]);
	team[2] = new card(other.team[2]);
	team[3] = new card(other.team[3]);
	team[4] = new card(other.team[4]);
	team[5] = new card(other.team[5]);
	team[6] = new card(other.team[6]);
	team[7] = new card(other.team[7]);
	team[8] = new card(other.team[8]);
	team[9] = new card(other.team[9]);
	team[10] = new goalie(other.team[10]);
}
player::player(string n) :m_name(n) {
	team[0] = new card;
	team[1] = new card;
	team[2] = new card;
	team[3] = new card;
	team[4] = new card;
	team[5] = new card;
	team[6] = new card;
	team[7] = new card;
	team[8] = new card;
	team[9] = new card;
	team[10] = new goalie;

	team[0]->setpos("ST");
	team[1]->setpos("ST");
	team[2]->setpos("LM");
	team[3]->setpos("CM");
	team[4]->setpos("CM");
	team[5]->setpos("RM");
	team[6]->setpos("LB");
	team[7]->setpos("CB");
	team[8]->setpos("CB");
	team[9]->setpos("RB");
	team[10]->setpos("GK");
}
/*
	ST	ST

LM	CM	CM	RM

LB	CB	CB	RB

	  GK
*/
void player::display() {
	cout << '\n';
	space(); space(); team[0]->display1(); space(); team[1]->display1(); cout << '\n';
	space(); space(); team[0]->display2(); space(); team[1]->display2(); cout << '\n';
	space(); space(); team[0]->display3(); space(); team[1]->display3(); cout << '\n';
	space(); space(); team[0]->display4(); space(); team[1]->display4(); cout << '\n';
	space(); space(); team[0]->display5(); space(); team[1]->display5(); cout << '\n';
	space(); space(); team[0]->display6(); space(); team[1]->display6(); cout << '\n';
	space(); space(); team[0]->display7(); space(); team[1]->display7(); cout << '\n';
	space(); space(); team[0]->display8(); space(); team[1]->display8(); cout << '\n';
	space(); space(); team[0]->display9(); space(); team[1]->display9(); cout << '\n';
	cout << '\n';
	team[2]->display1(); space(); team[3]->display1(); space(); team[4]->display1(); space(); team[5]->display1(); cout << '\n';
	team[2]->display2(); space(); team[3]->display2(); space(); team[4]->display2(); space(); team[5]->display2(); cout << '\n';
	team[2]->display3(); space(); team[3]->display3(); space(); team[4]->display3(); space(); team[5]->display3(); cout << '\n';
	team[2]->display4(); space(); team[3]->display4(); space(); team[4]->display4(); space(); team[5]->display4(); cout << '\n';
	team[2]->display5(); space(); team[3]->display5(); space(); team[4]->display5(); space(); team[5]->display5(); cout << '\n';
	team[2]->display6(); space(); team[3]->display6(); space(); team[4]->display6(); space(); team[5]->display6(); cout << '\n';
	team[2]->display7(); space(); team[3]->display7(); space(); team[4]->display7(); space(); team[5]->display7(); cout << '\n';
	team[2]->display8(); space(); team[3]->display8(); space(); team[4]->display8(); space(); team[5]->display8(); cout << '\n';
	team[2]->display9(); space(); team[3]->display9(); space(); team[4]->display9(); space(); team[5]->display9(); cout << '\n';
	cout << '\n';
	team[6]->display1(); space(); team[7]->display1(); space(); team[8]->display1(); space(); team[9]->display1(); cout << '\n';
	team[6]->display2(); space(); team[7]->display2(); space(); team[8]->display2(); space(); team[9]->display2(); cout << '\n';
	team[6]->display3(); space(); team[7]->display3(); space(); team[8]->display3(); space(); team[9]->display3(); cout << '\n';
	team[6]->display4(); space(); team[7]->display4(); space(); team[8]->display4(); space(); team[9]->display4(); cout << '\n';
	team[6]->display5(); space(); team[7]->display5(); space(); team[8]->display5(); space(); team[9]->display5(); cout << '\n';
	team[6]->display6(); space(); team[7]->display6(); space(); team[8]->display6(); space(); team[9]->display6(); cout << '\n';
	team[6]->display7(); space(); team[7]->display7(); space(); team[8]->display7(); space(); team[9]->display7(); cout << '\n';
	team[6]->display8(); space(); team[7]->display8(); space(); team[8]->display8(); space(); team[9]->display8(); cout << '\n';
	team[6]->display9(); space(); team[7]->display9(); space(); team[8]->display9(); space(); team[9]->display9(); cout << '\n';
	cout << '\n';
	space(); space(); space(); team[10]->display1(); cout << '\n';
	space(); space(); space(); team[10]->display2(); cout << '\n';
	space(); space(); space(); team[10]->display3(); cout << '\n';
	space(); space(); space(); team[10]->display4(); cout << '\n';
	space(); space(); space(); team[10]->display5(); cout << '\n';
	space(); space(); space(); team[10]->display6(); cout << '\n';
	space(); space(); space(); team[10]->display7(); cout << '\n';
	space(); space(); space(); team[10]->display8(); cout << '\n';
	space(); space(); space(); team[10]->display9(); cout << '\n';
}
void player::addCard(int pos, card* player) {
	delete team[pos];
	team[pos] = new card(player);
}
card* player::getCard(int pos) {
	return team[pos];
}

string player::name() {
	return m_name;
}