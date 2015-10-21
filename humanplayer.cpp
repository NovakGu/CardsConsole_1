#include "humanplayer.h"

using namespace std;

HumanPlayer::HumanPlayer(float chip, const string name, string signature, GameTaxes* game):
Player(chip,name,signature,game){}

bool HumanPlayer::move(istream&in){
	string decision;
	float betAmout;
	
	in>>decision;
	bool result;
	//need to change decision to specific taxes vocab
	if(decision=="fold"){
		reverseStatus();
		betAmout=0;
		result = true;
	}
	else if(decision=="pinggen"){
		while(true){
		betAmout=game->getCurrentAmount();
		if(getChipLeft()>=betAmout){
		game->setPotSize(betAmout);
		setChip(getChipLeft()-betAmout);
			}
		else{
			cout<<"not enough chip left"<<endl;
			continue;
		}
		break;
		}
		result = true;
	}
	else if(decision=="jiazhu"){
		while(true){
		in>>betAmout;
		if(getChipLeft()>=betAmout){
		game->setPotSize(betAmout);
		setChip(getChipLeft()-betAmout);
			}
		else{
			cout<<"not enough chip left"<<endl;
			continue;
		}
		break;
		}
		result = true;
		}
		else{
			cout<<"Error: invalid input, can't recgonize the instruction"
			result = false;
		}
		return result;
}