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
	virtual void notifyViews(std::string, float) = 0;
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
};
#endif