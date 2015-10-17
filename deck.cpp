#include "deck.h"
#include "cards.h"
#include "gameTaxes.h"

using namespace std;

Deck::Deck() {
	game = NULL;
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

