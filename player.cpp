#include "player.h"
using namespace std;

Player::Player(float chipNum, string name, string sig, GameTaxes *g) {
	activeStatus = false;
	allInStatus = false;
	this->chipLeft = chipNum;
	this->playerName = name;
	this->signature = sig;
	this->game = g;
	this->nextPlayer = 0;
	dealer = false;
	for (int i = 0; i < 2; i++) {
		hand[i] = 0;
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

int Player::getHand(int num) {
	return hand[num];
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

void Player::setChip(float num){
	chipLeft+=num;
}

void Player::setHand(int num, int flag) {
	if (flag == 1) {
		hand[0] = num;
	}
	else if (flag == 2) {
		hand[1] = num;
	}
	else {
		cout << "invalid flag input" << endl;
	}
}