#pragma once
#ifndef _TEXTDISPLAY_H__
#define _TEXTDISPLAY_H__
#include <iostream>
#incldue <string>
#include <stdlib.h>
#include <time.h>
#include "view.h"
class TextDisplay{
	public:
	std::string **table;
	TextDisplay();
	~TextDisplay();
	virtual void printConsole(std::string,std::string,float);
	virtual void printTable(std::ostream &out);
	virtual void notify(std::string, float);
	
};

#endif
