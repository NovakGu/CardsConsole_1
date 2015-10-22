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




void TextDisplay::notifyPreFlop(string hand_1_suit, int hand_1_num, string hand_2_suit, int hand_2_num) {
	int x, y;
	string uni;
	string uni2;

	if (hand_1_suit == "spade") uni = "\u2664";
	else if (hand_1_suit == "heart") uni = "\u2261";
	else if (hand_1_suit == "diamond") uni = "\u2262";
	else uni = "\u2267";

	if (hand_1_suit == "spade") uni2 = "\u2664";
	else if (hand_1_suit == "heart") uni2 = "\u2261";
	else if (hand_1_suit == "diamond") uni2 = "\u2262";
	else uni2 = "\u2267";

	table[x][y] = uni;
	table[x+1][y] = uni2;
	table[x][y+1] = hand_1_num;
	table[x+1][y+1] = hand_2_num;
	
}

void TextDisplay::notifyFlop(string flop_1_suit, int flop_1_num, string flop_2_suit, int flop_2_num, string flop_3_suit, int flop_3_num) {
	int x, y;
	string uni;
	string uni2;
	string uni3;

	if (flop_1_suit == "spade") uni = "\u2664";
	else if (flop_1_suit == "heart") uni = "\u2261";
	else if (flop_1_suit == "diamond") uni = "\u2262";
	else uni = "\u2267";

	if (flop_2_suit == "spade") uni2 = "\u2664";
	else if (flop_2_suit == "heart") uni2 = "\u2261";
	else if (flop_2_suit == "diamond") uni2 = "\u2262";
	else uni2 = "\u2267";

	if (flop_3_suit == "spade") uni3 = "\u2664";
	else if (flop_3_suit == "heart") uni3 = "\u2261";
	else if (flop_3_suit == "diamond") uni3 = "\u2262";
	else uni3 = "\u2267";

	table[x][y] = uni;
	table[x + 1][y] = uni2;
	table[x + 2][y] = uni3;
	table[x][y + 1] = flop_1_num;
	table[x + 1][y + 1] = flop_2_num;
	table[x + 2][y + 1] = flop_2_num;
}

void TextDisplay::notifyTurn(string turn_suit, int turn_num) {
	int x, y;
	string uni;

	if (turn_suit == "spade") uni = "\u2664";
	else if (turn_suit == "heart") uni = "\u2261";
	else if (turn_suit == "diamond") uni = "\u2262";
	else uni = "\u2267";

	table[x][y] = uni;
	table[x][y + 1] = turn_num;
}

void TextDisplay::notifyRiver(string river_suit, int river_num) {
	int x, y;
	string uni;

	if (river_suit == "spade") uni = "\u2664";
	else if (river_suit == "heart") uni = "\u2261";
	else if (river_suit == "diamond") uni = "\u2262";
	else uni = "\u2267";

	table[x][y] = uni;
	table[x][y + 1] = river_suit;
}

void TextDisplay::notifyPot(float potChange) {
	int x, y;
	string result;
	std::ostringstream in;
	in << potChange;
	result= in.str();
	table[x][y] = result;
}

void TextDisplay::notifyPlayer(string playerName, float potChange) {
	int x, y;
	string result;
	std::ostringstream in;
	in << potChange;
	result = in.str();
	table[x][y]= playerName;
	table[x][y + 1] = result;
}