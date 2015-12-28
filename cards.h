
#ifndef _CARDS_H__
#define _CARDS_H__
#include "gameTaxes.h"
#include <string>
#include <iostream>

class Card {
protected:
	int card_num;
	GameTaxes *game;
	Deck *deck;
public:
	Card(GameTaxes*,int);
	~Card();
	int getNum();
};


#endif