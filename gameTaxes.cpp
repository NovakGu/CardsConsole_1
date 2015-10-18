#include "gameTaxes.h"

using namespace std;

GameTaxes::GameTaxes() {
	GameNotifications = NULL;
	poolSize = 0;
	numOfPlayers = 0;
	tableName = "";
	deck = NULL;
}

GameTaxes::~GameTaxes() {
	if (deck != NULL) {
		for (int i = 0; i < 52; i++) {
			delete deck->getCard(i);
		}
	}
}

void GameTaxes::notify(string choice, float betSize) {
	GameNotifications->notifyViews(choice, betSize);
}

void GameTaxes::gameInit(ConmmuChannel *GameNotific) {
	deck->shuffleCards();
	GameNotifications = GameNotific;
}

//evaluate
int evaluate(string allCards) {
	int cardsNum[7];
	int cardsSuit[7];
	int strSize = 21;
	string buff="";
	int index=1;
	int numOfCardsSameSuite = 0; //num of cards with 
	int currNumOfCardSameSuite = 0;
	//string maxSameSuite = "";
	int numOfCardsSameNum = 0;
	int currNumOfCardsMaxSameNum = 0;
	int maxSameNum = 0;
	int currMaxNum = 0;
	int numConsec = 0;
	int maxConsec = 0;
	int currNumConsec = 0;
	int value = 0;
	/*
	// unfinished
	*/

	//evaluate all cards
	//evaluate for same suit
	for (int i = 1; i < 5; i++) {
		for (int j = 0; j < 7; j++) {
			if (i == cardsSuit[j]) currNumOfCardSameSuite++;
		}
		if (currNumOfCardSameSuite > numOfCardsSameSuite) {
			numOfCardsSameSuite = currNumOfCardSameSuite;
		}
		currNumOfCardSameSuite = 0;
	}

	//evaluate for same num
	for (int i = 3; i < 16; i++) {
		for (int j = 0; j < 7; j++) {
			if (i == cardsNum[j]) currNumOfCardsMaxSameNum++;
		}
		if (currNumOfCardsMaxSameNum > numOfCardsSameNum) {
			numOfCardsSameNum = currNumOfCardsMaxSameNum;
			maxSameNum = i;
		}
		currNumOfCardsMaxSameNum = 0;
	}

	//evaluate for consec
	//bubble sort cardsNum[]
	int temp;
	bool flag = false;
	for (int i = 0; i < 7; i++) {
		flag = true;
		for (int j = 0; j < 7 - i - 1; j++) {
			if (cardsNum[j] > cardsNum[j + 1]) {
				temp = cardsNum[j];
				cardsNum[j] = cardsNum[j + 1];
				cardsNum[j + 1] = temp;
				flag = false;
			}
		}
		if (flag) break;
	}

	for (int i = 0; i <= 2; i++) {
		for (int j = i+4; j >i; j--) {
			if (cardsNum[j] == cardsNum[j -1]+1) {
				currNumConsec += 1;
				
			}
		}
		if (currNumConsec > numConsec) {
			numConsec = currNumConsec;
			maxConsec = cardsNum[i + numConsec - 1];
		}
		currNumConsec = 0;
	}

		//check Royal Flush/ Straight Flush/ Flush
	if (numOfCardsSameSuite >= 5 && numConsec >= 5 && maxConsec == 15) {
		return 1;
		}

		//check straight

		//check four of a kind

		//check Full House/three of a kind

		//check two pair/one pair

		//check high card

	
	
	}



