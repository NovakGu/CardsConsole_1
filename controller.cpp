#include "controller.h"
#include "humanplayer.h"
#include "bot.h"
#include "textdisplay.h"

using namespace std;

Controller::Controller() {
	game = new GameTaxes;
	for (int controllerCtorIndex = 0; controllerCtorIndex < 6; controllerCtorIndex++) {
		player[controllerCtorIndex] = NULL;
	}
	textDisplay = NULL;
	//replayFile = savedfile;
	dealer = 0;
	nextPlayer = 0;
	nextCard = 0;
}

Controller::~Controller() {
	delete game;
	delete textDisplay;
	for (int controllerDtorIndex = 0; controllerDtorIndex < 6; controllerDtorIndex++) {
		delete player[controllerDtorIndex];
	}
}

void Controller::notifyPreFlopViews(int hand_1_num, int hand_2_num,int preFlopPlayerNum) {
	textDisplay->notifyPreFlop(hand_1_num, hand_2_num, preFlopPlayerNum);

}

void Controller::notifyFlopViews(int flop_1_num, int flop_2_num, int flop_3_num) {
	textDisplay->notifyFlop(flop_1_num, flop_2_num, flop_3_num);

}

void Controller::notifyTurnViews(int turn_1_num) {
	textDisplay->notifyTurn(turn_1_num);

}

void Controller::notifyRiverViews(int river_1_num) {
	textDisplay->notifyRiver(river_1_num);

}

void Controller::notifyPotViews(float addPot) {
	textDisplay->notifyPot(addPot);
}

void Controller::notifyPlayerViews(string name,float changeChip) {
	textDisplay->notifyPlayer(name, changeChip);
}

void Controller::gameSetup(istream&in, GameTaxes&game_0) {
	string input, status, tableName, setplayer, playerNum;
	string playerName = "";
	float chipNum;
	while (true) {
		cout << "Please enter the following options: table/player/done" << endl;
		in >> input;
		if (input == "done") {
			//status = game->setStatus(string name, float chip);
			if (player[0]->getChipLeft < 0) {
				cout << "Setup was unsuccessful due to not enough chip left" << endl;
			}
			else if (game->getTableName == "") {
				cout << "Setup was unsuccessful due to NULL	table name" << endl;
			}
			else {
				cout << "Setup is successful" << endl;
				break;
			}
		}
		else if (input == "table") {
			in >> tableName;
			game->setTableName(tableName);
			tableName = game->getTableName();
			cout << "Table name is set to " << tableName << endl;
		}
		else if (input == "player") {
			
				cout << "These are the players on table" << endl;
				for (int playerSetupIndex = 0; playerSetupIndex < 6; playerSetupIndex++) {
					cout << "Player " << playerSetupIndex << " : Name: " << player[playerSetupIndex]->getPlayerName() << " # Chip Left: " << player[playerSetupIndex]->getChipLeft() << endl;
				}
				while (true) {
				cout << "Do you want to make changes? (y/n)" << endl;
				in >> input;
				if (input == "n") {
					cout << "Player status sets successfully" << endl << endl;
					for (int playerPrintIndex = 0; playerPrintIndex < 6; playerPrintIndex++) {
						cout << "Player " << playerPrintIndex << " : Name: " << player[playerPrintIndex]->getPlayerName() << " # Chip Left: " << player[playerPrintIndex]->getChipLeft() << endl;
					}
					break;
				}
				else if (input == "y") {
					cout << "Please enter the Player Number" << endl;
					in >> playerNum;
					stringstream convert;
					int intPlayer;
					convert << playerNum;
					convert >> intPlayer;
					convert.str("");
					convert.clear();
					cout << "Player #" << intPlayer << " Name: " << player[intPlayer]->getPlayerName() << " # Chip Left: " << player[intPlayer]->getChipLeft() << endl;
					cout << "Change Player Name to: ";
					in >> playerName;
					if (playerName == "");
					else {
						player[intPlayer]->setPlayerName(playerName);
					}
					cout << "Change Chip Left to: ";
					in >> chipNum;
					player[intPlayer]->setChip(chipNum);
					cout << "Finish Setting, results: "<< "Player " << intPlayer << " : Name: " << player[intPlayer]->getPlayerName() << " # Chip Left: " << player[intPlayer]->getChipLeft() << endl;
				}
			}
		}
		else {
			cout << "INVALID INPUT, please re-enter" << endl;
		}

	}
}



void Controller::start() {
	bool roundComplete = false;
	cout << "Hello guest, welcome to cards console" << endl;
	cout << "Enter (table) to take a seat, Enter (exit) to exit the game" << endl;
	string startCommand;
	cin >> startCommand;




	if (startCommand == "table") {
		delete textDisplay;
		textDisplay = new TextDisplay();
		game->gameInit(this);
		textDisplay->printTable(cout);
		for (int playerDataIndex = 0; playerDataIndex < 6; playerDataIndex++) {
			while (true) {
				string type;
				cout << "Type in player type for Player-" << playerDataIndex << "(human/bot)" << endl;
				cin >> type;
				if (type == "human") {
					string name, sig;
					float chip;
					cout << "Your name is?" << endl;
					cin >> name;
					cout << "Your Signature?" << endl;
					cin >> sig;
					cout << "How much dou you want to bring onto the table?" << endl;
					cin >> chip;
					//need to protect invalid input
					player[playerDataIndex] = new HumanPlayer(chip, name, sig, game);
					break;
				}
				else if (type == "bot") {
					string name = "Bot";
					string sig = "Welcome to the console";
					float chip = 5000.0f;
					player[playerDataIndex] = new Bot(chip, name, sig, game);
					break;
				}
				else {
					cout << "Invalid Type, redirecting to type setup..." << endl;
					continue;
				}
			}
		}
	}





	else {
		exit(0);
	}
	// set a for loop to control the game flow
	//every time all the player finish betting
	//break the while loop inside for loop to continue the game flow
	//check table situation after every player's decision
	//if the game stops in the middle of a round set a flag to break the for loop and start a new round
	//if a game reach final end then break the outter for loop to start a new round
	while (true) {
		bool exit=false;
		if (roundComplete) {
			delete textDisplay;
			textDisplay = new TextDisplay();
			game->gameInit(this);
			textDisplay->printTable(cout);
		}

		for (int notifyPlayerIndex = 0; notifyPlayerIndex < 6; notifyPlayerIndex++) {
			notifyPlayerViews(player[notifyPlayerIndex]->getPlayerName(), player[notifyPlayerIndex]->getChipLeft());
		}

		for (int roundIndex = 0; roundIndex < 5; roundIndex++) {
			bool breakFor = false;
			if (roundIndex == 0) {
				
				for (int preFlopIndex = 0; preFlopIndex < 6; preFlopIndex++) {
					notifyPreFlopViews(game->sendNumToController(nextCard), game->sendNumToController(nextCard + 1),preFlopIndex);
					//I did not start from dealer;
					player[preFlopIndex]->setHand(game->sendNumToController(nextCard), 1);
					++nextCard;
					player[preFlopIndex]->setHand(game->sendNumToController(nextCard), 2);
					++nextCard;
				}
			}
			else if (roundIndex == 1) {
				notifyFlopViews(game->sendNumToController(nextCard), game->sendNumToController(nextCard + 1), game->sendNumToController(nextCard + 2));
				cardsOnTable[0] = game->sendNumToController(nextCard);
				cardsOnTable[1] = game->sendNumToController(nextCard+1);
				cardsOnTable[2] = game->sendNumToController(nextCard+2);
				nextCard += 3;
			}
			else if (roundIndex == 2) {
				notifyTurnViews(game->sendNumToController(nextCard));
				cardsOnTable[3] = game->sendNumToController(nextCard);
				nextCard += 1;
			}
			else if (roundIndex == 3) {
				notifyRiverViews(game->sendNumToController(nextCard));
				cardsOnTable[4] = game->sendNumToController(nextCard);
				nextCard += 1;
			}

			string command;
			while (cin >> command) {
				if (command == "setup") {
					textDisplay->printTable(cout);
					gameSetup(cin, *game);
					textDisplay->printTable(cout);
				}

				else if (command == "push") {
					bool sucess = player[nextPlayer]->move(cin);
					textDisplay->printTable(cout);
					bool situation = EvaluateSituation();
					
					

					if (!sucess) {
						cout << "Failed to push decision" << endl;
						textDisplay->printTable(cout);
						cout << "This should not be displaying...?" << endl;
					}
					
					if (roundIndex ==5) {
						string playerRemain = remainPlayer();
						int currentHigh;
						int currentResult;
						int playerWon=0;
						for (int playerActiveIndex = 0; playerActiveIndex < 5; playerActiveIndex++) {
							if (player[playerActiveIndex]->getStatus == false) {
								continue;
							}
							else {
								 currentResult = game->evaluatePlayer(allCards(playerActiveIndex));
								 if (currentResult > currentHigh) {
									 currentHigh = currentResult;
									 playerWon = playerActiveIndex;
								 }
							}
						}
						player[playerWon]->setChip(game->getPoolSize());
						game->setPotSize(0);
						bool breakFor = true;
						roundComplete = true;
						break;
					}
					else if (situation) {
						int playerWin = 0;
						for (int f = 0; f < 5; f++) {
							if (player[f]->getStatus) {
								playerWin = f;
								break;
							}
						}
						player[playerWin]->setChip(game->getPoolSize());
						game->setPotSize(0);
						bool breakFor = true;
						roundComplete = true;
						break;
					}
					
				}
				else if (command == "exit") {
					exit = true;
					breakFor = true;
					break;
				}
			}
			if (breakFor) {
				break;
			}
		}
		if (exit = true) {
			break;
		}
	}
}

bool Controller::EvaluateSituation() {
	int playerRemains = 0;
	for (int evaluateSituationIndex = 0; evaluateSituationIndex < 5; evaluateSituationIndex++) {
		if (player[evaluateSituationIndex]->getStatus()) playerRemains++;
	}
	if (playerRemains == 1) {
		return true;
	}
	else {
		return false;
	}
}

string Controller::remainPlayer() {
	string remains = "";
	for (int checkRemainIndex = 0; checkRemainIndex < 5; checkRemainIndex++) {
		if (player[checkRemainIndex]->getStatus()) {
			string player;
			stringstream in;
			in << checkRemainIndex;
			in >> player;
			remains += player;
		}
	}
	return remains;
}

int* Controller::allCards(int playerNum) {
	int tableCards[7];

	for (int tableCardsIndex = 0; tableCardsIndex < 5; tableCardsIndex++) {
		tableCards[tableCardsIndex] = cardsOnTable[tableCardsIndex];
	}

	for (int handCardsIndex = 0; handCardsIndex < 2; handCardsIndex++) {
		 tableCards[handCardsIndex +5] = player[playerNum]->getHand[handCardsIndex];
	}
	return tableCards;
	
}

