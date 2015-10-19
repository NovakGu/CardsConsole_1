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
		in>>betAmout;
		game->setPotSize(betAmout);
		result = true;
	}
	else if(decision=="jiazhu"){
		in>>betAmout;
		game->setPotSize(betAmout);
		result = true;
		}
		else{
			cout<<"Error: invalid input, can't recgonize the instruction"
			result = false;
		}
		return result;
}