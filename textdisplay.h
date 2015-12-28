
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
	virtual void notifyPreFlop(int,int,int);
	virtual void notifyFlop(int,int,int);
	virtual void notifyTurn(int);
	virtual void notifyRiver(int);
	virtual void notifyPot(float);
	virtual void notifyPlayer(std::string, float);
	//need to add fold notify
	
};

#endif
