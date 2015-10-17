#pragma once
#ifndef _CONTROLLER_H__
#define _CONTROLLER_H__
#include "gameTaxes.h"
#include "player.h"
#include "view.h"
#include <stdlib.h>
#include <string>
#include <stdbool.h>
#include <iostream>
#include <sstream>
class Controller{
protected:
	Player *player[6];
	View *textDisplay;
	GameTaxes *game;
	std::string replayFile;
public:
	void gameSetup(std::istream & input, GameTaxes & game);
	Controller(std::string);
	~Controller();
	void notifyViews(std::string, int);


};
#endif 