#pragma once
#ifndef _DECK_H__
#define _DECK_H__
#include "cards.h"
#include "gameTaxes.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string>
class Deck {
protected:
	Card *cards[52];
public:
	void shuffleCards();
};

#endif