#pragma once
#ifndef _CARDS_H__
#define _CARDS_H__
#include "gameTaxes.h"
#include "table.h"
#include <string>
#include <iostream>

class Card {
protected:
	int card_num;
	std::string card_suit;
//	Player *player;
	GameTaxes *game;
	Deck *deck;
public:
	Card(GameTaxes*,/*Player*,*/ std::string, int);
	~Card();
	int getNum();
	std::string getSuit();
};


#endif