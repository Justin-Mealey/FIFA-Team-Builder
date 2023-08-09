#include "card.h"

card::card(string ovr, string pos, string name, string stat1, string stat2, string stat3, string stat4, string stat5, string stat6) {
	m_ovr = ovr;
	m_pos = pos;
	m_name = name;
	m_stat1 = stat1;
	m_stat2 = stat2;
	m_stat3 = stat3;
	m_stat4 = stat4;
	m_stat5 = stat5;
	m_stat6 = stat6;
}
card::card(card* const other) {
	m_ovr = other->m_ovr;
	m_pos = other->m_pos;
	m_name = other->m_name;
	m_stat1 = other->m_stat1;
	m_stat2 = other->m_stat2;
	m_stat3 = other->m_stat3;
	m_stat4 = other->m_stat4;
	m_stat5 = other->m_stat5;
	m_stat6 = other->m_stat6;
}
goalie::goalie(card* const other) {
	m_ovr = other->getOVR();
	m_pos = other->getPOS();
	m_name = other->getNAME();
	m_stat1 = other->getS1();
	m_stat2 = other->getS2();
	m_stat3 = other->getS3();
	m_stat4 = other->getS4();
	m_stat5 = other->getS5();
	m_stat6 = other->getS6();
}
card::card() {
	m_ovr = "00";
	m_pos = "NA";
	m_name = "EMPTY";
	m_stat1 = "00";
	m_stat2 = "00";
	m_stat3 = "00";
	m_stat4 = "00";
	m_stat5 = "00";
	m_stat6 = "00";
}

void card::display() {
	display1();
	cout << '\n';
	display2();
	cout << '\n';
	display3();
	cout << '\n';
	display4();
	cout << '\n';
	display5();
	cout << '\n';
	display6();
	cout << '\n';
	display7();
	cout << '\n';
	display8();
	cout << '\n';
	display9();
	cout << '\n';
}

void card::display1() {
	cout << "|-----------------|";
}
void card::display2() {
	cout << "| " << m_ovr << "              |";
}
void card::display3() {
	cout << "| " << m_pos << "              |";
}
void card::display4() {
	string name = m_name;
	to16(name);
	cout << "| " << name << "|";
}
void card::display5() {
	cout << "|                 |";
}
void card::display6() {
	cout << "| " << m_stat1 << " PAC | " << m_stat4 << " DRI |";
}
void card::display7() {
	cout << "| " << m_stat2 << " SHO | " << m_stat5 << " DEF |";
}
void card::display8() {
	cout << "| " << m_stat3 << " PAS | " << m_stat6 << " PHY |";
}
void card::display9() {
	cout << "|-----------------|";
}

goalie::goalie() : card() {}
goalie::goalie(string ovr, string pos, string name, string stat1, string stat2, string stat3, string stat4, string stat5, string stat6) 
	:card(ovr, pos, name, stat1, stat2, stat3, stat4, stat5, stat6){}

void goalie::display6() {
	cout << "| " << m_stat1 << " DIV | " << m_stat4 << " REF |";
}
void goalie::display7() {
	cout << "| " << m_stat2 << " HAN | " << m_stat5 << " SPE |";
}
void goalie::display8() {
	cout << "| " << m_stat3 << " KIC | " << m_stat6 << " POS |";
}