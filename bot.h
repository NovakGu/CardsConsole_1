#pragma once
#ifndef _BOT_H__
#define _BOT_H__
#include "player.h"
#include "gameTaxes.h"
#include <stdlib.h>
#include <time.h>
#include <string>

class Bot : public Player{
public:
	Bot(float, const std::string, std::string, GameTaxes*);
	bool move(std::istream& input);

};

#endif