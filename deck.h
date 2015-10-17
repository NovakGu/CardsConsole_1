#pragma once
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
public:
	Deck();
	void shuffleCards();
	void setGame(GameTaxes*);
	void preFlop();
	void Flop();
	void Turn();
	void River();
};

#endif