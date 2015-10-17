#pragma once
#ifndef _CARDS_H__
#define _CARDS_H__
#include "gameTaxes.h"
#include "table.h"
#include <string>
#include <iostream>

class Card {
protected:
	std::string card_num;
	std::string card_suit;
//	Player *player;
	GameTaxes *game;
public:
	Card(GameTaxes*, /*Player*,*/ std::string);
	~Card();
	std::string getNum();
	std::string getSuit();
};


#endif