#include "deck.h"
#include "cards.h"
#include "gameTaxes.h"

using namespace std;

Deck::Deck() {
	game = NULL;
	index = 0;
	for (int i = 0; i < 52; i++) {
		if (i <= 12) {
			cards[i] = new Card(game, "heart", i); 
		}
		else if (i <= 25) {
			cards[i] = new Card(game, "spade", i - 12 + 2);
		}
		else if (i <= 37) {
			cards[i] = new Card(game, "club", i - 25 + 2);
		}
		else {
			cards[i] = new Card(game, "diamond", i - 37 + 2);
		}
	}
}

Card *Deck::getCard(int num_index){
	return cards[num_index];
}


int Deck::getIndex() {
	return index;
}

void Deck::shuffleCards() {
	int index = 0;
	int length = 52;
	Card* median;
	int value;

	if (NULL == cards)
		return;
	srand((int)time(0)); 
	for (index = 0; index < length; index++) {
		value = rand() % length;

		median = cards[index];
		cards[index] = cards[value];
		cards[value] = median;
	}
}

void Deck::setGame(GameTaxes* g) {
	game = g;
}

string Deck::preFlop() {
	string cardsOnHand = "";
	//reference on index
	int &ind = index;
	for (int i = 0; i < 2; i++) {
		cardsOnHand = to_string(cards[index]->getNum) + cards[index]->getSuit;
		ind++;
	}
	//test if index got changed
	return cardsOnHand;
}

string Deck::Flop() {
	string cardsOnFlop = "";
	int &ind = index;
	for (int i = 0; i < 3; i++) {
		cardsOnFlop = to_string(cards[index]->getNum) + cards[index]->getSuit;
		ind++;
	}
	return cardsOnFlop;
}

string Deck::Turn() {
	string cardsOnTurn = "";
	int &ind = index;
	for (int i = 0; i < 1; i++) {
		cardsOnTurn = to_string(cards[index]->getNum) + cards[index]->getSuit;
		ind++;
	}
	return cardsOnTurn;
}

string Deck::River() {
	string cardsOnRiver = "";
	int &ind = index;
	for (int i = 0; i < 1; i++) {
		cardsOnRiver = to_string(cards[index]->getNum) + cards[index]->getSuit;
		ind++;
	}
	return cardsOnRiver;
}
