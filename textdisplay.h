#pragma once
#ifndef _TEXTDISPLAY_H__
#define _TEXTDISPLAY_H__
#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <time.h>
#include "view.h"
class TextDisplay: public View{
	public:
	std::string **table;
	TextDisplay();
	~TextDisplay();
	//virtual void printConsole(std::string,std::string,float);
	virtual void printTable(std::ostream &out);
	virtual void notifyPreFlop(std::string, int, std::string, int);
	virtual void notifyFlop(std::string, int, std::string, int, std::string, int);
	virtual void notifyTurn(std::string, int);
	virtual void notifyRiver(std::string, int);
	virtual void notifyPot(float);
	virtual void notifyPlayer(std::string, float);

	
};

#endif
