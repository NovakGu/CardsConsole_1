#pragma once
#ifndef _PLAYER_H__
#define _PLAYER_H__
#include "gameTaxes.h"
#include "cards.h"
#include <string>
#include <iostream>
#include <stdbool.h>
#include <string>
class Player {
protected:
	bool activeStatus;
	float chipLeft;
	std::string playerName;
	std::string hand[2];
	std::string signature;
	GameTaxes *game;
	bool dealer;
	int nextPlayer;
public:
	Player(float, std::string, std::string, GameTaxes*);
	virtual ~Player();
	bool getStatus();
	float getChipLeft();
	std::string getPlayerName();
	std::string *getHand();
	std::string getSignature();
	virtual bool move(std::istream&)=0;
	bool zeroChips();
	void reverseStatus();
	bool getDealer();
	void setDealer(bool);
	void setChip(float);
	void setPlayerName(std::string);
	//need to keep track opn nexy player
	//need to examine if next player is vacent or not
	//increment?
	
};


#endif