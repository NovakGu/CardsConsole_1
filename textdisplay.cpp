#include "textdisplay.h"
using namespace std;

TextDisplay::TextDisplay() :View() {
	table = new string*[tablesize];
	int a = tablesize*consoleRatio;
	int b = tablesize;

	for (int x = tablesize; x <= tablesize; x++)
	{
		table[x] = new string[tablesize];
		for (int y = -consoleRatio*tablesize; y <= consoleRatio*tablesize; y++)
		{
			float d = (y / a)*(y / a) + (x / b)*(x / b);
			if (d > 0.90 && d < 1.1)
			{
				table[x][y] = "*";
			}
			else
			{
				table[x][y] = " ";
			}
		}
	}
}

TextDisplay::~TextDisplay() {
	for (int i = 0; i < tablesize; i++) {
		delete[] table[i];
	}
	delete[] table;
}

void TextDisplay::printTable(ostream &out) {
	out << endl;
	for (int i = 0; i < tablesize; i++) {
		for (int j = 0; j < tablesize; j++) {
			out << table[i][j];
		}
		out << endl;
	}
}




void TextDisplay::notifyPreFlop(int hand_1_num, int hand_2_num,int preFlopPlayer) {
	int x, y;
	if (preFlopPlayer == 1) {
		int x = 0;
		int y = 0;
	}
	else if (preFlopPlayer == 2) {
		int x = 4;
		int y = 4;
	}
	else if (preFlopPlayer == 3) {
		int x = 8;
		int y = 8;
	}
	else if (preFlopPlayer == 4) {
		int x = 12;
		int y = 12;
	}
	else if (preFlopPlayer == 5) {
		int x = 16;
		int y = 16;
	}
	else {
		int x = 20;
		int y = 20;
	}

	string uni;
	string uni2;
	int suit_1= hand_1_num - ((hand_1_num / 4) * 4);
	int suit_2= hand_2_num - ((hand_2_num / 4) * 4);
	int num_1 = (hand_1_num / 4) + 1;
	int num_2 = (hand_2_num / 4) + 1;

	if (suit_1 == 0) uni = "\u2664";
	else if (suit_1 == 1) uni = "\u2261";
	else if (suit_1 == 2) uni = "\u2262";
	else uni = "\u2267";

	if (suit_2 == 0) uni2 = "\u2664";
	else if (suit_2 == 1) uni2 = "\u2261";
	else if (suit_2 == 2) uni2 = "\u2262";
	else uni2 = "\u2267";

	table[x][y] = uni;
	table[x+1][y] = uni2;

	if (num_1 == 1) {
		table[x][y + 1] = "A";
	}
	else if (num_1 == 11) {
		table[x][y + 1] = "J";
	}
	else if (num_1 == 12) {
		table[x][y + 1] = "Q";
	}
	else if (num_1 == 13) {
		table[x][y + 1] = "K";
	}
	else {
		table[x][y + 1] = to_string(num_1);
	}

	if (num_2 == 1) {
		table[x + 1][y + 1] = "A";
	}
	else if (num_2 == 11) {
		table[x + 1][y + 1] = "J";
	}
	else if (num_2 == 12) {
		table[x + 1][y + 1] = "Q";
	}
	else if (num_2 == 13) {
		table[x + 1][y + 1] = "K";
	}
	else {
		table[x + 1][y + 1] = to_string(num_2);
	}
	
}

void TextDisplay::notifyFlop(int flop_1_num, int flop_2_num, int flop_3_num) {
	int x = 100;
	int y = 100;
	string uni;
	string uni2;
	string uni3;
	int suit_1 = flop_1_num - ((flop_1_num / 4) * 4);
	int suit_2 = flop_2_num - ((flop_2_num / 4) * 4);
	int suit_3 = flop_3_num - ((flop_3_num / 4) * 4);
	int num_1 = (flop_1_num / 4) + 1;
	int num_2 = (flop_2_num / 4) + 1;
	int num_3 = (flop_3_num / 4) + 1;

	if (suit_1 == 0) uni = "\u2664";
	else if (suit_1 == 1) uni = "\u2261";
	else if (suit_1 == 2) uni = "\u2262";
	else uni = "\u2267";

	if (suit_2 == 0) uni2 = "\u2664";
	else if (suit_2 == 1) uni2 = "\u2261";
	else if (suit_2 == 2) uni2 = "\u2262";
	else uni2 = "\u2267";

	if (suit_3 == 0) uni3 = "\u2664";
	else if (suit_3 == 1) uni3 = "\u2261";
	else if (suit_3 == 2) uni3 = "\u2262";
	else uni3 = "\u2267";

	table[x][y] = uni;
	table[x + 1][y] = uni2;
	table[x + 2][y] = uni3;


	if (num_1 == 1) {
		table[x][y + 1] = "A";
	}
	else if (num_1 == 11) {
		table[x][y + 1] = "J";
	}
	else if (num_1 == 12) {
		table[x][y + 1] = "Q";
	}
	else if (num_1 == 13) {
		table[x][y + 1] = "K";
	}
	else {
		table[x][y + 1] = to_string(num_1);
	}


	if (num_2 == 1) {
		table[x + 1][y + 1] = "A";
	}
	else if (num_2 == 11) {
		table[x + 1][y + 1] = "J";
	}
	else if (num_2 == 12) {
		table[x + 1][y + 1] = "Q";
	}
	else if (num_2 == 13) {
		table[x + 1][y + 1] = "K";
	}
	else {
		table[x + 1][y + 1] = to_string(num_2);
	}


	if (num_3 == 1) {
		table[x + 2][y + 1] = "A";
	}
	else if (num_3 == 11) {
		table[x + 2][y + 1] = "J";
	}
	else if (num_3 == 12) {
		table[x + 2][y + 1] = "Q";
	}
	else if (num_3 == 13) {
		table[x + 2][y + 1] = "K";
	}
	else {
		table[x + 2][y + 1] = to_string(num_3);
	}

}

void TextDisplay::notifyTurn(int turn_num) {
	int x = 110;
	int y = 100;
	string uni;
	int suit_1 = turn_num - ((turn_num / 4) * 4);
	int num_1 = (turn_num / 4) + 1;

	if (suit_1 == 0) uni = "\u2664";
	else if (suit_1 == 1) uni = "\u2261";
	else if (suit_1 == 2) uni = "\u2262";
	else uni = "\u2267";

	table[x][y] = uni;

	if (num_1 == 1) {
		table[x][y + 1] = "A";
	}
	else if (num_1 == 11) {
		table[x][y + 1] = "J";
	}
	else if (num_1 == 12) {
		table[x][y + 1] = "Q";
	}
	else if (num_1 == 13) {
		table[x][y + 1] = "K";
	}
	else {
		table[x][y + 1] = to_string(num_1);
	}
}

void TextDisplay::notifyRiver(int river_num) {
	int x = 115;
	int y = 100;
	string uni;
	int suit_1 = river_num - ((river_num / 4) * 4);
	int num_1 = (river_num / 4) + 1;

	if (suit_1 == 0) uni = "\u2664";
	else if (suit_1 == 1) uni = "\u2261";
	else if (suit_1 == 2) uni = "\u2262";
	else uni = "\u2267";

	table[x][y] = uni;

	if (num_1 == 1) {
		table[x][y + 1] = "A";
	}
	else if (num_1 == 11) {
		table[x][y + 1] = "J";
	}
	else if (num_1 == 12) {
		table[x][y + 1] = "Q";
	}
	else if (num_1 == 13) {
		table[x][y + 1] = "K";
	}
	else {
		table[x][y + 1] = to_string(num_1);
	}
}

void TextDisplay::notifyPot(float potChange) {
	int x = 130;
	int y = 90;
	string result;
	std::ostringstream in;
	in << potChange;
	result= in.str();
	table[x][y] = result;
}

void TextDisplay::notifyPlayer(string playerName, float potChange) {
	int x = 200;
	int y=200;

	string result;
	std::ostringstream in;
	in << potChange;
	result = in.str();
	table[x][y]= playerName;
	table[x][y + 1] = result;
}