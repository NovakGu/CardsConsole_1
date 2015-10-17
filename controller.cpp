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

void Controller::gameSetup(istream&in,GameTaxes&game_0) {
	while (true) {
	
	}

}