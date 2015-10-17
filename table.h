#pragma once
#ifndef _TABLE_H__
#define _TABLE_H__
#include <string>
#include <iostream>
#include <stdbool.h>
#include "player.h"
#include "cards.h"
#include "gameTaxes.h"

class Table {
protected:
	Player *player[6];
	Card *wastePool[17];
	Game *game;
	int poolSize;
	std::string tableName;

public:


};
#endif