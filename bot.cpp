
#include "bot.h"

using namespace std;

Bot::Bot(float ChipNum, string name, string sig, GameTaxes *game) : Player(ChipNum, name, sig, game) {}

Bot::~Bot(){}

bool Bot::move(){
	float betAmount;
	
	bool result=false;
	while(true){
		betAmount=game->getCurrentAmount();
		if(getChipLeft()>=betAmount){
			game->setPotSize(betAmount);
			setChip(getChipLeft()-betAmount);
			result =true;
		}
		else{
			setChip(getChipLeft());
			result=true;
		}
	}
	return result;
}