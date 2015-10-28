#include "controller.h"
#include "humanplayer.h"
#include "bot.h"
#include "textdisplay.h"

using namespace std;

Controller::Controller(string savedfile) {
	game = new GameTaxes;
	for (int i = 0; i < 6; i++) {
		player[i] = NULL;
	}
	textDisplay = NULL;
	replayFile = savedfile;
}

Controller::~Controller() {
	delete game;
	delete textDisplay;
	for (int i = 0; i < 6; i++) {
		delete player[i];
	}
}

void Controller::notifyPreFlopViews(string hand_1, string hand_2, int hand_1_num, int hand_2_num) {
	textDisplay->notifyPreFlop(hand_1, hand_1_num, hand_2, hand_2_num);

}

void Controller::notifyFlopViews(string flop_1, string flop_2, string flop_3, int flop_1_num, int flop_2_num, int flop_3_num) {
	textDisplay->notifyFlop(flop_1, flop_1_num, flop_2,flop_2_num, flop_3, flop_3_num);

}

void Controller::notifyTurnViews(string turn_1, int turn_1_num) {
	textDisplay->notifyTurn(turn_1, turn_1_num);

}

void Controller::notifyRiverViews(string river_1, int river_1_num) {
	textDisplay->notifyRiver(river_1, river_1_num);

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
			status = game->setStatus(string name, float chip);
			if (status == "done") {
				cout << "Setup is successful" << endl;
				break;
			}
			else {
				cout << "Setup was unsuccessful due to " << status << endl;
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
				for (int i = 0; i < 6; i++) {
					cout << "Player " << i << " : Name: " << player[i]->getPlayerName() << " # Chip Left: " << player[i]->getChipLeft() << endl;
				}
				while (true) {
				cout << "Do you want to make changes? (y/n)" << endl;
				in >> input;
				if (input == "n") {
					cout << "Player status sets successfully" << endl << endl;
					for (int i = 0; i < 6; i++) {
						cout << "Player " << i << " : Name: " << player[i]->getPlayerName() << " # Chip Left: " << player[i]->getChipLeft() << endl;
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
	// set a for loop to control the game flow
	//every time all the player finish betting
	//break the while loop inside for loop to continue the game flow
	//check table situation after every player's decision
	//if the game stops in the middle of a round set a flag to break the for loop and start a new round
	//if a game reach final end then break the outter for loop to start a new round

	string command;
	while (cin >> command) {
		if (command == "new_table") {
			delete textDisplay;
			textDisplay = new TextDisplay();
			game->gameInit(this);
			textDisplay->printTable(cout);
			for (int i = 0; i < 6; i++) {
				while (true) {
					string type;
					cout << "Type in player type for Player-" << i << "(human/bot)" << endl;
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
							player[i] = new HumanPlayer(chip, name, sig, game);
							break;
						}
						else if (type == "bot") {
							string name = "Bot";
							string sig = "Welcome to the console";
							float chip = 5000.0f;
							player[i] = new Bot(chip, name, sig, game);
							break;
						}
						else {
							cout << "Invalid Type, redirecting to type setup..." << endl;
							continue;
						}
				}
			}
		}

		else if (command == "setup") {
			textDisplay->printTable(cout);
			gameSetup(cin, *game);
			textDisplay->printTable(cout);
		}

		else if (command == "push") {
			bool sucess = player[nextPlayer]->move(cin);
			bool situation = EvaluateSituation();
			string playerRemain = remainPlayers();
			int player = evaluate();
			if (!sucess) {
				cout << "Failed to push decision" << endl;
				textDisplay->printTable(cout);
				cout << "This should not be displaying...?" << endl;
			}
			if (situation) {
				
			}
		}
	}
}