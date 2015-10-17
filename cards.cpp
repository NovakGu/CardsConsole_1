#include "cards.h"
using namespace std;

Card::Card(GameTaxes* g, Deck* d, string suit, int num) {
	game = g;
	deck = d;
	card_suit = suit;
	card_num = num;
}

Card::~Card() {
}

int Card::getNum() {
	return card_num;
}

string Card::getSuit() {
	return card_suit;
}