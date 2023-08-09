#include "game.h"

game::game(player& p, database d) :m_p(p), m_d(d), m_players(0), m_replacesUsed(0) {
	for (int i = 0; i < 11; i++)
		m_spotsFilled[i] = false;
	for (int i = 0; i < 129; i++)
		m_usedCardAlready[i] = false;
}

void game::play() {
	cout << "Welcome to the card game simulator! In this game, you will try to strategically craft your squad of 11." << '\n';
	cout << "How to play: " << '\n';
	cout << "You will have two commands (case sensitive) that will allow you to build your team, these commands are:" << '\n';
	cout << "pick - get a choice of 4 cards to add to your team, the first card being a card that replaces a previously chosen player (if eligible)." << '\n';
	cout << "You only get 3 replacements per game, so use them wisely to improve your squad!" << '\n';
	cout << "display - see the current status of your team in a 4-4-2 formation." << '\n';
	cout << "Good luck!" << '\n';
	while (m_players <= 10) {
		string command;
		do {
			cout << "Enter a command: ";
			cin >> command;
			if (command == "pick" || command == "display")
				break;
		} while (true);
		if (command == "pick")
			pick();
		else //command is display
			m_p.display();
	}
	while (m_replacesUsed < 3) {
		cout << "You still have " << 3 - m_replacesUsed << " replaces left! Choose a card (1 or 2) to add it or type 0 to choose neither" << endl;
		int c1, c2, p1, p2;
		c1 = randomReplacement(p1);
		m_usedCardAlready[c1] = true;
		c2 = randomReplacement(p2);
		m_usedCardAlready[c2] = true;

		m_d.display2(c1, c2);

		int choice;
		do {
			cout << "Pick your card: (0, 1, or 2) ";
			cin >> choice;
			if (choice == 0 || choice == 1 || choice == 2)
				break;
			else
				cout << "Incorrect input, please type 0, 1, or 2" << endl;
		} while (true);

		switch (choice) {
			case 1:
				potentiallySwitchPositionOfReplacement(p1);
				m_p.addCard(p1, m_d.getCard(c1)); 
			case 2:
				potentiallySwitchPositionOfReplacement(p2);
				m_p.addCard(p2, m_d.getCard(c2));
		}
		m_replacesUsed++;
	}
	cout << "This is your final team:" << '\n';
	m_p.display();
	cout << '\n' << "Congratulations" << m_p.name() << ", your team is finished with an overall average of " << avg() << "!" << '\n';
}

void game::pick() { 
	int player1, player2, player3, player4, pos1, pos2, pos3, pos4; //player's are integer elements in the database of our cards, pos's are elements 0-10 for our team
	if (m_players == 0 || m_replacesUsed == 3) //no replace options, just 4 random players
		player1 = randomNewCard(pos1); 
	else
		player1 = randomReplacement(pos1);
	m_usedCardAlready[player1] = true; //mark it as seen, don't wanna see it again
	if (m_players <= 7) {
		player2 = randomNewCard(pos2, pos1); //this excludes pos1, so the second card will be a different position as the first card
		m_usedCardAlready[player2] = true;
		player3 = randomNewCard(pos3, pos1, pos2); //3rd card shown won't be same position as pos1 or pos2
		m_usedCardAlready[player3] = true;
		player4 = randomNewCard(pos4, pos1, pos2, pos3); //4th card will be a unique position
	}
	else if (m_players == 8) { //impossible to have 4 unique positions, we only have 3 open spots!
		player2 = randomNewCard(pos2, pos1); //this excludes pos1
		m_usedCardAlready[player2] = true;
		player3 = randomNewCard(pos3, pos1, pos2); //3rd card shown won't be same position as pos1 or pos2
		m_usedCardAlready[player3] = true;
		player4 = randomNewCard(pos4); //4th card will NOT be a unique position
	}
	else if (m_players == 9) {
		player2 = randomNewCard(pos2, pos1);
		m_usedCardAlready[player2] = true;
		player3 = randomNewCard(pos3);
		m_usedCardAlready[player3] = true;
		player4 = randomNewCard(pos4);
	}
	else { //we only have one spot left
		player2 = randomNewCard(pos2);
		m_usedCardAlready[player2] = true;
		player3 = randomNewCard(pos3);
		m_usedCardAlready[player3] = true;
		player4 = randomNewCard(pos4);
	}

	m_usedCardAlready[player4] = true;

	cout << '\n';
	m_d.display4(player1, player2, player3, player4);
	int choice;
	do {
		cout << "Pick your card (1, 2, 3 or 4): ";
		cin >> choice; 
		if (choice == 1 || choice == 2 || choice == 3 || choice == 4)
			break;
		else
			cout << "Incorrect input, please type 1, 2, 3 or 4" << endl;
	} while (true);

	switch (choice) {
		case 1:
			if((m_players == 0 || m_replacesUsed == 3) == false)
				potentiallySwitchPositionOfReplacement(pos1);
			m_p.addCard(pos1, m_d.getCard(player1)); //add card to our players team
			m_spotsFilled[pos1] = true;		   //mark that position as filled
			if (m_players == 0 || m_replacesUsed == 3)
				m_players++;
			else
				m_replacesUsed++;
			break;
		case 2:
			m_p.addCard(pos2, m_d.getCard(player2));
			m_spotsFilled[pos2] = true;
			m_players++;
			break;
		case 3:
			m_p.addCard(pos3, m_d.getCard(player3));
			m_spotsFilled[pos3] = true;
			m_players++;
			break;
		case 4:
			m_p.addCard(pos4, m_d.getCard(player4));
			m_spotsFilled[pos4] = true;
			m_players++;
			break;
	}
}

// returns the element in database the random card we picked is at
int game::randomNewCard(int& positionElem, int ex1, int ex2, int ex3) { // will be a position still needed, and a card never seen before
	int r;
	srand((unsigned int)time(NULL));
	do {
		r = rand() % 11;
	} while (m_spotsFilled[r] == true || r == ex1 || r == ex2 || r == ex3); //get a new number if the position is filled or excluded
	positionElem = r;
	//now we know what spot we're filling
	int databaseElem;
	srand((unsigned int)time(NULL));
	switch (r) {
	case 0: //ST
	case 1: //ST
		do { databaseElem = rand() % 18; } while (m_usedCardAlready[databaseElem] == true);
		break;
	case 2: //LM
		do { databaseElem = rand() % 15 + 18; } while (m_usedCardAlready[databaseElem] == true);
		break;
	case 3: //CM
	case 4: //CM
		do { databaseElem = rand() % 18 + 33; } while (m_usedCardAlready[databaseElem] == true);
		break;
	case 5: //RM
		do { databaseElem = rand() % 15 + 51; } while (m_usedCardAlready[databaseElem] == true);
		break;
	case 6: //LB
		do { databaseElem = rand() % 15 + 66; } while (m_usedCardAlready[databaseElem] == true);
		break;
	case 7: //CB
	case 8: //CB
		do { databaseElem = rand() % 18 + 81; } while (m_usedCardAlready[databaseElem] == true);
		break;
	case 9: //RB
		do { databaseElem = rand() % 15 + 99; } while (m_usedCardAlready[databaseElem] == true);
		break;
	case 10: //GK
		do { databaseElem = rand() % 15 + 114; } while (m_usedCardAlready[databaseElem] == true);
		break;
	}
	return databaseElem;
}
int game::randomNewCard(int& positionElem) {
	return randomNewCard(positionElem, 11, 11, 11); //a placeholder number higher than 10 or lower than 0 (i.e. 11) effectively excludes nothing 
}
int game::randomNewCard(int& positionElem, int ex1) {
	return randomNewCard(positionElem, ex1, 11, 11);
}
int game::randomNewCard(int& positionElem, int ex1, int ex2) {
	return randomNewCard(positionElem, ex1, ex2, 11);
}

int game::randomReplacement(int& positionElem) {
	int r;
	srand((unsigned int)time(NULL));
	do {
		r = rand() % 11;
	} while (m_spotsFilled[r] == false);
	positionElem = r;
	//now we know what spot we're gonna give a replacement option for
	int databaseElem;
	srand((unsigned int)time(NULL));
	switch (r) {
	case 0: //ST
	case 1: //ST
		do { databaseElem = rand() % 18; } while (m_usedCardAlready[databaseElem] == true);
		break;
	case 2: //LM
		do { databaseElem = rand() % 15 + 18; } while (m_usedCardAlready[databaseElem] == true);
		break;
	case 3: //CM
	case 4: //CM
		do { databaseElem = rand() % 18 + 33; } while (m_usedCardAlready[databaseElem] == true);
		break;
	case 5: //RM
		do { databaseElem = rand() % 15 + 51; } while (m_usedCardAlready[databaseElem] == true);
		break;
	case 6: //LB
		do { databaseElem = rand() % 15 + 66; } while (m_usedCardAlready[databaseElem] == true);
		break;
	case 7: //CB
	case 8: //CB
		do { databaseElem = rand() % 18 + 81; } while (m_usedCardAlready[databaseElem] == true);
		break;
	case 9: //RB
		do { databaseElem = rand() % 15 + 99; } while (m_usedCardAlready[databaseElem] == true);
		break;
	case 10: //GK
		do { databaseElem = rand() % 15 + 114; } while (m_usedCardAlready[databaseElem] == true);
		break;
	}
	return databaseElem;
}

void game::potentiallySwitchPositionOfReplacement(int& pos) {
	string s;
	switch (pos) {
		case 0:
		case 1:
			if (m_spotsFilled[0] == true && m_spotsFilled[1] == true) {
				do {
					cout << "Enter the striker you want to replace (type right or left): ";
					cin >> s;
				} while (!(s == "right" || s == "left"));
				
				if (s == "left")
					pos = 0;
				else if (s == "right")
					pos = 1;
			}
			break;
		case 3:
		case 4:
			if (m_spotsFilled[3] == true && m_spotsFilled[4] == true) {
				do {
					cout << "Enter the center mid you want to replace (type right or left): ";
					cin >> s;
				} while (!(s == "right" || s == "left"));

				if (s == "left")
					pos = 3;
				else if (s == "right")
					pos = 4;
			}
			break;
		case 7:
		case 8:
			if (m_spotsFilled[0] == true && m_spotsFilled[1] == true) {
				do {
					cout << "Enter the center back you want to replace (type right or left): ";
					cin >> s;
				} while (!(s == "right" || s == "left"));

				if (s == "left")
					pos = 7;
				else if (s == "right")
					pos = 8;
			}
			break;
	}
}

double game::avg() {
	double sum = stoi(m_p.getCard(0)->getOVR()) + stoi(m_p.getCard(1)->getOVR()) + stoi(m_p.getCard(2)->getOVR()) + stoi(m_p.getCard(3)->getOVR())
		+ stoi(m_p.getCard(4)->getOVR()) + stoi(m_p.getCard(5)->getOVR()) + stoi(m_p.getCard(6)->getOVR()) + stoi(m_p.getCard(7)->getOVR()) +
		stoi(m_p.getCard(8)->getOVR()) + stoi(m_p.getCard(9)->getOVR()) + stoi(m_p.getCard(10)->getOVR());
	return sum / 11.0;
}