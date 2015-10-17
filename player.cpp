#include "player.h"
using namespace std;

Player::Player(float chipNum, string name, string sig, GameTaxes *g) {
	activeStatus = false;
	chipLeft = chipNum;
	playerName = name;
	signature = sig;
	game = g;
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

