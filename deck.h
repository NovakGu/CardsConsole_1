#ifndef _DECK_H__
#define _DECK_H__
#include "cards.h"
#include "gameTaxes.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string>
#include <ctime>
class Deck {
protected:
	Card *cards[52];
	GameTaxes* game;
	int index;
public:
	Deck();
	Card *getCard(int);
	int getIndex();
	void shuffleCards();
	void setGame(GameTaxes*);
	int returnNextNum(int);
	//std::string returnNextSuit(int);
};

#endif