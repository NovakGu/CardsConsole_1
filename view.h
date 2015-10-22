#pragma once
#ifndef _VIEW_H__
#define _VIEW_H__
#include<string>
#include<iostream>
#include<stdlib.h>
class View{
	protected:
	const int tablesize;
	const int tableRadius;
	const int consoleRatio;
	public:
	View();
	virtual ~View()=0;
	virtual void printConsole(std::string,std::string,float)=0;
	virtual void printTable(std::ostream &out)=0;
	virtual void notify(std::string, float)=0;
};
#endif