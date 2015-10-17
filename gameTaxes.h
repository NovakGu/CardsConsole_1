#pragma once
#ifndef _GAMETAXES_H__
#define _GAMETAXES_H__
#include "cards.h"
#include "deck.h"
#include <iostream>
#include <string>
#include <stdbool.h>
#include <stdlib.h>

class ConmmuChannel {
public:
	virtual void notifyViews(std::string, std::string) = 0;
};

class GameTaxes {
protected:
	ConmmuChannel *GameNotifications;
	int poolSize;
	int numOfPlayers;
	std::string tableName;
	Deck *deck;
public:
	void clearGame();
	GameTaxes();
	~GameTaxes();
	void notify(std::string, int);
	bool zeroChips();
	void gameInit(ConmmuChannel *GameNotification, std::string);
	int checkWin(std::string);
	void newRound();
	int getNumOfPlayer();
	int getPoolSize();
	std::string getTableName();
	void setTableName(std::string);
};
#endif