#pragma once
#ifndef _GAMETAXES_H__
#define _GAMETAXES_H__
#include "cards.h"
#include "deck.h"
#include <iostream>
#include <string>
#include <stdbool.h>
#include <stdlib.h>
#include <sstream>


class ConmmuChannel {
public:
	virtual void notifyPreFlopViews(std::string, std::string, int, int)=0;
	virtual void notifyFlopViews(std::string, std::string, std::string, int, int, int)=0;
	virtual void notifyTurnViews(std::string, int)=0;
	virtual void notifyRiverViews(std::string, int)=0;
	virtual void notifyPotViews(float)=0;
	virtual void notifyPlayerViews(std::string, float)=0;
};

class GameTaxes {
protected:
	ConmmuChannel *GameNotifications;
	float potSize;
	int numOfPlayers;
	int tableRadius;
	int consoleRatio;
	std::string tableName;
	Deck *deck;
	float currentAmount;
	int blind;
public:
	//void clearGame();
	GameTaxes();
	~GameTaxes();
	void notify(std::string, float);
	//bool zeroChips();
	void gameInit(ConmmuChannel *GameNotification);
	std::string evaluate(std::string);
	void newRound();
	float getPoolSize();
	std::string getTableName();
	void setTableName(std::string);
	void setPotSize(float);
	float getCurrentAmount();
	void setCurrentAmount(float);
	bool setStatus(std::string, float);
	void setBlind(int);
	//need a checkwin function returns boolean
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