#ifndef CARD
#define CARD

/*
|-----------------|
| 89              |
| LW              |
| NEYMAR JR       |
|				  |
| 87 PAC | 93 DRI |
| 83 SHO | 37 DEF |
| 85 PAS | 61 PHY |
|-----------------| 
*/

#include <string>
#include <iostream>
#include "aux.h"
using namespace std;

class card {
public:
	card();
	card(card* const other);
	virtual ~card(){}
	card(string ovr, string pos, string name, string stat1, string stat2, string stat3, string stat4, string stat5, string stat6);
	void display();
	void display1();
	void display2();
	void display3();
	void display4();
	void display5();
	virtual void display6();
	virtual void display7();
	virtual void display8();
	void display9();
	void setpos(string p) { m_pos = p; }
	string getOVR() { return m_ovr; }
	string getPOS() { return m_pos; }
	string getNAME() { return m_name; }
	string getS1() { return m_stat1; }
	string getS2() { return m_stat2; }
	string getS3() { return m_stat3; }
	string getS4() { return m_stat4; }
	string getS5() { return m_stat5; }
	string getS6() { return m_stat6; }
protected:
	string m_ovr;
	string m_pos; 
	string m_name; 
	string m_stat1;
	string m_stat2;
	string m_stat3;
	string m_stat4;
	string m_stat5;
	string m_stat6;
};


class goalie : public card {
public:
	goalie();
	goalie(card* const other);
	goalie(string ovr, string pos, string name, string stat1, string stat2, string stat3, string stat4, string stat5, string stat6);
	virtual void display6();
	virtual void display7();
	virtual void display8();
};

#endif 
