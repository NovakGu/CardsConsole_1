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
	//std::string replayFile;
	int dealer;
	int nextPlayer;
	int nextCard;
	int cardsOnTable[5];
public:
	void gameSetup(std::istream & input, GameTaxes & game);
	void start();
	Controller();
	~Controller();
	void notifyPreFlopViews(int, int,int);
	void notifyFlopViews(int, int, int);
	void notifyTurnViews(int);
	void notifyRiverViews(int);
	void notifyPotViews(float);
	void notifyPlayerViews(std::string, float);
	bool EvaluateSituation();
	std::string remainPlayer();
	int* allCards(int);
	//need a function to send back all the players
	//that still in play
	//function returns a string
	//function's output is used for Controller::start()
	//check each players status to achieve
	//check if I forgot to change players' status
	//when a player fold or start a new round

	//need a situation evaluation situation
	//return true when
	//1->there's only one player in play
	//2->final bet is over
	//3->all player decides all in
	//4->1 player have chips left, the rest choose all
	//in due to less chip
	//evaluate function will take in a string with all players in seat
	//returns a integer meaning the winning player
	//haven't decided what to do with the situation
	//when two or more player have the same level of
	//hand
};
#endif 