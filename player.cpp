#include "player.h"
using namespace std;

Player::Player(float chipNum, string name, string sig, GameTaxes *g) {
	activeStatus = false;
	chipLeft = chipNum;
	playerName = name;
	signature = sig;
	game = g;
	dealer = false;
	for (int i = 0; i < 2; i++) {
		hand[i] = "";
	}
}

Player::~Player() {}

bool Player::getStatus() {
	return activeStatus;
}

float Player::getChipLeft() {
	return chipLeft;
}

string Player::getPlayerName() {
	return playerName;
}

string *Player::getHand() {
	string *handPointer;
	handPointer = &hand;
}

string Player::getSignature() {
	return signature;
}

bool Player::zeroChips() {
	if (chipLeft==0){
		return true;
	}	
	return false;
	
}

void Player::reverseStatus(){
	activeStatus=!(activeStatus);
	
}

bool Player::getDealer(){
		return dealer;
}

void Player::setDealer(bool status){
		dealer = status;
}