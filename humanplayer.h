#pragma once
#include "player.h"
#include <iostream>
#include <string>

class HumanPlayer : public Player{
 public:
  HumanPlayer(float, const std::string, std::string, GameTaxes*);
  bool move(std::istream&);
	
};