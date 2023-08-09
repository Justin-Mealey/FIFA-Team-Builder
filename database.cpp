#include "database.h"
//18 ST - 15 LM - 18CM - 15RM - 15LB - 18CB - 15RB - 15 GK --- EACH POSITION IS SORTED
//8 positions
database::database() {
	//[0] - [17]
	m_cards.push_back(new card("98", "ST", "MESSI", "94", "97", "96", "99", "40", "79"));
	m_cards.push_back(new card("97", "ST", "MBAPPE", "99", "97", "87", "99", "43", "85"));
	m_cards.push_back(new card("96", "ST", "RONALDO", "94", "98", "86", "94", "38", "84"));
	m_cards.push_back(new card("95", "ST", "KANE", "90", "98", "92", "90", "53", "92"));
	m_cards.push_back(new card("91","ST","LEWANDOWSKI","78","91","78","86","43","82"));
	m_cards.push_back(new card("90", "ST", "DROGBA", "88", "91", "76", "81", "47", "89"));
	m_cards.push_back(new card("88","ST","HAALAND","89","91","65","80","49","87"));
	m_cards.push_back(new card("87","ST","AGUERO","89","87","77","89","23","68"));
	m_cards.push_back(new card("87","ST","THURAM","90","88","82","87","57","85"));
	m_cards.push_back(new card("86","ST","LUKAKU","80","85","75","77","38","82"));
	m_cards.push_back(new card("79","ST","JONG","48","78","71","70","46","77"));
	m_cards.push_back(new card("78","ST","BRENNER","85","78","71","83","39","61"));
	m_cards.push_back(new card("77","ST","BALOTELLI","66","81","72","76","25","78"));
	m_cards.push_back(new card("76","ST","EKITIKE","74","75","60","76","25","69"));
	m_cards.push_back(new card("74","ST","HAHN","69","74","68","70","55","83"));
	m_cards.push_back(new card("73","ST","LARRIVEY","50","75","58","61","42","74"));
	m_cards.push_back(new card("72","ST","NTEKA","73","71","64","72","54","82"));
	m_cards.push_back(new card("72","ST","RUBIO","66","73","65","72","47","73"));
	//[18] - [32]
	m_cards.push_back(new card("93", "LM", "COMAN", "97", "90", "88", "93", "37", "75"));
	m_cards.push_back(new card("92","LM","MANE","93","87","85","91","47","80"));
	m_cards.push_back(new card("90", "LM", "GOMES", "95", "87", "87", "94", "58", "75"));
	m_cards.push_back(new card("87","LM","FRED","88","80","84","88","65","78"));
	m_cards.push_back(new card("86","LM","EKAMBI","90","86","82","85","31","75"));
	m_cards.push_back(new card("85","LM","RASHFORD","91","86","80","85","46","77"));
	m_cards.push_back(new card("84","LM","PAULINHO","93","84","80","79","45","80"));
	m_cards.push_back(new card("81","LM","HAZARD","78","77","80","84","54","66"));
	m_cards.push_back(new card("77","LM","PEPE","85","66","68","80","32","53"));
	m_cards.push_back(new card("71","LM","AMILTON","86","68","64","71","33","66"));
	m_cards.push_back(new card("70","LM","LIMNIOS","72","67","65","73","39","58"));
	m_cards.push_back(new card("69","LM","PERRIN","82","65","62","71","35","60"));
	m_cards.push_back(new card("68","LM","ALVAREZ","73","60","61","72","53","46"));
	m_cards.push_back(new card("68","LM","QUINA","69","66","66","72","44","48"));
	m_cards.push_back(new card("67","LM","BONNET","70","65","67","70","47","58"));
	//[33] - [50]
	m_cards.push_back(new card("97","CM","BELLINGHAM","90","90","94","98","93","94"));
	m_cards.push_back(new card("97","CM","MODRIC","87","87","99","99","86","84"));
	m_cards.push_back(new card("97","CM","BRUYNE","84","92","99","95","85","87"));
	m_cards.push_back(new card("92","CM","BENZEMA","83","89","87","92","81","86"));
	m_cards.push_back(new card("91","CM","KROOS","80","85","93","86","79","76"));
	m_cards.push_back(new card("91","CM","CASEMIRO","76","78","80","77","90","92"));
	m_cards.push_back(new card("90","CM","POGBA","81","86","89","90","80","91"));
	m_cards.push_back(new card("89","CM","THIAGO","85","84","89","87","75","73"));
	m_cards.push_back(new card("88","CM","RAMSEY","85","81","86","88","80","85"));
	m_cards.push_back(new card("88","CM","JORGINHO","83","76","92","88","84","84"));
	m_cards.push_back(new card("87","CM","BECKHAM","78","84","92","85","71","78"));
	m_cards.push_back(new card("86","CM","THIAGO","61","72","87","90","72","69"));
	m_cards.push_back(new card("81","CM","MCKENNIE","83","75","77","81","79","84"));
	m_cards.push_back(new card("80","CM","SOW","77","69","77","78","77","79"));
	m_cards.push_back(new card("76","CM","EVANDER","73","71","76","80","67","69"));
	m_cards.push_back(new card("75","CM","DUNCAN","73","64","72","74","74","81"));
	m_cards.push_back(new card("74","CM","JENSEN","67","62","75","72","65","69"));
	m_cards.push_back(new card("71","CM","BERO","72","71","69","71","67","82"));
	//51 - 65
	m_cards.push_back(new card("93","RM","LLORENTE","95","87","90","91","90","89"));
	m_cards.push_back(new card("92","RM","MARIO","90","90","90","92","83","82"));
	m_cards.push_back(new card("91","RM","JOAQUIN","90","91","94","91","52","80"));
	m_cards.push_back(new card("91","RM","SALAH","91","90","83","91","47","77"));
	m_cards.push_back(new card("90","RM","SILVA","81","81","87","95","63","71"));
	m_cards.push_back(new card("87","RM","MURPHY","92","80","84","88","78","78"));
	m_cards.push_back(new card("84","RM","OTAVIO","81","72","83","87","65","73"));
	m_cards.push_back(new card("83","RM","ORSOLINI","87","80","82","80","46","73"));
	m_cards.push_back(new card("78","RM","JUN","89","69","63","84","49","66"));
	m_cards.push_back(new card("77","RM","ISI","84","73","72","80","39","63"));
	m_cards.push_back(new card("74","RM","CAPELLE","64","72","74","73","69","69"));
	m_cards.push_back(new card("74","RM","SANCHEZ","84","64","73","73","39","46"));
	m_cards.push_back(new card("67","RM","SHVED","73","67","61","71","36","49"));
	m_cards.push_back(new card("66","RM","PINCHI","76","61","60","69","42","55"));
	m_cards.push_back(new card("66","RM","PEREZ","76","54","60","68","46","65"));
	//66 - 80
	m_cards.push_back(new card("95","LB","ALBA","95","83","92","93","90","88"));
	m_cards.push_back(new card("94","LB","HERNANDEZ","99","80","90","90","90","91"));
	m_cards.push_back(new card("91","LB","CANCELO","90","78","88","90","85","80"));
	m_cards.push_back(new card("90","LB","ZINCHENKO","90","78","89","90","87","81"));
	m_cards.push_back(new card("87","LB","FIRPO","90","76","82","86","85","87"));
	m_cards.push_back(new card("86","LB","MENDES","95","65","80","84","81","80"));
	m_cards.push_back(new card("84","LB","DAVIES","94","66","77","85","76","77"));
	m_cards.push_back(new card("82","LB","DIGNE","78","69","80","79","77","76"));
	m_cards.push_back(new card("82","LB","TAVARES","87","60","74","82","75","82"));
	m_cards.push_back(new card("78","LB","BERNAT","74","64","76","81","75","58"));
	m_cards.push_back(new card("76","LB","ANGILERI","79","71","76","75","70","80"));
	m_cards.push_back(new card("74","LB","MITTELSTADT","78","61","68","74","71","67"));
	m_cards.push_back(new card("63","LB","WALSTAD","79","36","48","57","57","74"));
	m_cards.push_back(new card("63","LB","AMRO","71","47","60","55","57","69"));
	m_cards.push_back(new card("62","LB","ALLOH","76","39","52","66","56","53"));
	//81 - 98
	m_cards.push_back(new card("96","CB","DIJK","88","65","80","83","97","94"));
	m_cards.push_back(new card("96","CB","DIAS","88","48","83","83","97","97"));
	m_cards.push_back(new card("95","CB","MARQUINHOS","90","64","84","84","95","90"));
	m_cards.push_back(new card("91","CB","KIMPEMBE","89","56","80","83","91","94"));
	m_cards.push_back(new card("91","CB","RAMOS","83","72","78","77","92","88"));
	m_cards.push_back(new card("90","CB","AGUERD","86","60","75","76","92","91"));
	m_cards.push_back(new card("89","CB","KING","83","58","72","78","92","86"));
	m_cards.push_back(new card("89","CB","PIQUE","83","58","77","74","88","87"));
	m_cards.push_back(new card("87","CB","AKE","81","58","77","78","86","85"));
	m_cards.push_back(new card("85","CB","KEHRER","84","50","77","78","85","87"));
	m_cards.push_back(new card("84","CB","KEANE","60","54","68","67","86","85"));
	m_cards.push_back(new card("81","CB","GABRIEL","68","36","60","58","83","80"));
	m_cards.push_back(new card("80","CB","DIER","54","64","70","65","80","84"));
	m_cards.push_back(new card("78","CB","REAM","61","49","73","75","78","75"));
	m_cards.push_back(new card("73","CB","KOTCHAP","82","25","50","51","74","76"));
	m_cards.push_back(new card("68","CB","SCRECIU","76","38","56","56","67","72"));
	m_cards.push_back(new card("67","CB","MEDLEY","67","30","45","53","66","74"));
	m_cards.push_back(new card("67","CB","CORREIA","59","38","61","62","66","64"));
	//99 - 113
	m_cards.push_back(new card("94","RB","HAKIMI","99","81","90","91","90","91"));
	m_cards.push_back(new card("92","RB","LORENZO","97","78","86","87","90","91"));
	m_cards.push_back(new card("87","RB","PAVARD","81","65","80","79","88","85"));
	m_cards.push_back(new card("87","RB","TRIPPIER","88","72","87","83","85","82"));
	m_cards.push_back(new card("86","RB","FABIO","90","67","82","86","82","81"));
	m_cards.push_back(new card("85","RB","WALKER","91","63","77","78","80","82"));
	m_cards.push_back(new card("82","RB","DOUDERA","93","74","75","82","78","74"));
	m_cards.push_back(new card("82","RB","SIMAKAN","76","43","67","69","85","83"));
	m_cards.push_back(new card("79","RB","CASH","80","67","71","75","74","76"));
	m_cards.push_back(new card("78","RB","DALOT","79","60","73","78","73","77"));
	m_cards.push_back(new card("75","RB","CEDRIC","71","61","70","75","73","64"));
	m_cards.push_back(new card("72","RB","QUINI","71","60","65","69","69","61"));
	m_cards.push_back(new card("70","RB","DOM","75","58","63","63","65","73"));
	m_cards.push_back(new card("68","RB","FILA","78","47","62","63","63","68"));
	m_cards.push_back(new card("66","RB","TONG","79","51","60","61","60","67"));
	//114 - 128
	m_cards.push_back(new goalie("96","GK","COURTOIS","90","95","85","97","60","95"));
	m_cards.push_back(new goalie("93","GK","SAMBA","89","95","95","94","73","90"));
	m_cards.push_back(new goalie("90","GK","DE GEA","91","84","80","92","54","88"));
	m_cards.push_back(new goalie("90","GK","NEUER","87","88","91","88","56","91"));
	m_cards.push_back(new goalie("89","GK","DONNARUMMA","91","84","81","90","54","86"));
	m_cards.push_back(new goalie("88","GK","BLAKE","90","88","86","91","61","89"));
	m_cards.push_back(new goalie("82","GK","PICKFORD","84","77","87","87","51","80"));
	m_cards.push_back(new goalie("81","GK","ARMANI","80","76","70","87","44","82"));
	m_cards.push_back(new goalie("84","GK","PATRICIO","84","80","77","83","55","82"));
	m_cards.push_back(new goalie("75","GK","DARLOW","77","71","68","78","58","74"));
	m_cards.push_back(new goalie("75","GK","ROBLES","76","73","72","77","52","73"));
	m_cards.push_back(new goalie("74","GK","STANKOVIC","75","73","62","77","42","74"));
	m_cards.push_back(new goalie("73","GK","BOLAT","70","76","74","71","44","73"));
	m_cards.push_back(new goalie("70","GK","SALIN","68","69","68","70","30","69"));
	m_cards.push_back(new goalie("56","GK","MCCABE","58","54","57","57","36","56"));
}
database::database(const database& other) {
	for (int i = 0; i < 114; i++) {
		m_cards.push_back(new card(other.m_cards[i]));
	}
	for (int j = 114; j < 129; j++) {
		m_cards.push_back(new goalie(other.m_cards[j]));
	}
}
database::~database() {
	for (int i = 0; i < m_cards.size(); i++) {
		delete m_cards[i];
	}
}

void database::display4(int a, int b, int c, int d) {
	m_cards[a]->display1(); space(); m_cards[b]->display1(); space(); m_cards[c]->display1(); space(); m_cards[d]->display1(); cout << '\n';
	m_cards[a]->display2(); space(); m_cards[b]->display2(); space(); m_cards[c]->display2(); space(); m_cards[d]->display2(); cout << '\n';
	m_cards[a]->display3(); space(); m_cards[b]->display3(); space(); m_cards[c]->display3(); space(); m_cards[d]->display3(); cout << '\n';
	m_cards[a]->display4(); space(); m_cards[b]->display4(); space(); m_cards[c]->display4(); space(); m_cards[d]->display4(); cout << '\n';
	m_cards[a]->display5(); space(); m_cards[b]->display5(); space(); m_cards[c]->display5(); space(); m_cards[d]->display5(); cout << '\n';
	m_cards[a]->display6(); space(); m_cards[b]->display6(); space(); m_cards[c]->display6(); space(); m_cards[d]->display6(); cout << '\n';
	m_cards[a]->display7(); space(); m_cards[b]->display7(); space(); m_cards[c]->display7(); space(); m_cards[d]->display7(); cout << '\n';
	m_cards[a]->display8(); space(); m_cards[b]->display8(); space(); m_cards[c]->display8(); space(); m_cards[d]->display8(); cout << '\n';
	m_cards[a]->display9(); space(); m_cards[b]->display9(); space(); m_cards[c]->display9(); space(); m_cards[d]->display9(); cout << '\n';
}
void database::display2(int a, int b) {
	m_cards[a]->display1(); space(); m_cards[b]->display1(); cout << '\n';
	m_cards[a]->display2(); space(); m_cards[b]->display2(); cout << '\n';
	m_cards[a]->display3(); space(); m_cards[b]->display3(); cout << '\n';
	m_cards[a]->display4(); space(); m_cards[b]->display4(); cout << '\n';
	m_cards[a]->display5(); space(); m_cards[b]->display5(); cout << '\n';
	m_cards[a]->display6(); space(); m_cards[b]->display6(); cout << '\n';
	m_cards[a]->display7(); space(); m_cards[b]->display7(); cout << '\n';
	m_cards[a]->display8(); space(); m_cards[b]->display8(); cout << '\n';
	m_cards[a]->display9(); space(); m_cards[b]->display9(); cout << '\n';
}

card* database::getCard(int elem) {
	return m_cards[elem];
}