#ifndef _GAMETAXES_H__
#define _GAMETAXES_H__
#include "cards.h"
#include "deck.h"
#include "7Eval.h"
#include "5Eval.h"
#include <iostream>
#include <string>
#include <stdbool.h>
#include <stdlib.h>
#include <sstream>


class ConmmuChannel {
public:
	virtual void notifyPreFlopViews(int, int)=0;
	virtual void notifyFlopViews(int, int, int)=0;
	virtual void notifyTurnViews(int)=0;
	virtual void notifyRiverViews(int)=0;
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
	GameTaxes();
	~GameTaxes();
	void gameInit(ConmmuChannel *GameNotification);
	void newRound();
	float getPoolSize();
	std::string getTableName();
	void setTableName(std::string);
	void setPotSize(float);
	void addToPotSize(float);
	float getCurrentAmount();
	void setCurrentAmount(float);
	int sendNumToController(int);
	int evaluatePlayer(int[]);



	//need a checkwin function returns boolean
	//bool setStatus(std::string, float);
	//void setBlind(int);
	//std::string evaluate(std::string);
	//void notify(std::string, float);
	//bool zeroChips();
	//void clearGame();
	//std::string sendSuitToController(int);
};
#endif