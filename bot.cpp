#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

Bot::Bot(float ChipNum, string name, string sig, GameTaxes *game ):(ChipNum,name,sig,game){}

Bot::~Bot(){}

bool Bot::move(){
	float betAmount;
	
	bool result=false;
	while(true){
		betAmount=game->getCurrentAmout();
		if(getChipLeft()>=betAmount){
			game->setPotSize(betAmout);
			setChip(getChipLeft()-betAmout);
			result =true;
		}
		else{
			setChip(getChipLeft());
			result=true;
		}
	}
	return result;
}