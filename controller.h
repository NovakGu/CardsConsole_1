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
class Controller : public ConmmuChannel{
protected:
	Player *player[6];
	View *textDisplay;
	GameTaxes *game;
	std::string replayFile;
	int dealer;
	int nextPlayer;
public:
	void gameSetup(std::istream & input, GameTaxes & game);
	void start();
	Controller(std::string);
	~Controller();
	void notifyPreFlopViews(std::string, std::string,int,int);
	void notifyFlopViews(std::string, std::string, std::string, int, int, int);
	void notifyTurnViews(std::string,int);
	void notifyRiverViews(std::string,int);
	void notifyPotViews(float);
	void notifyPlayerViews(std::string, float);
	//need a function to send back all the players
	//that still in play
	//function returns a string
	//function's output is used for Controller::start()
	//check each players status to achieve
	//check if I forgot to change players' status
	//when a player fold or start a new round
};
#endif 