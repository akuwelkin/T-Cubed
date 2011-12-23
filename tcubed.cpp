#include <iostream>
#include "tcubed.h"

using namespace std;

tcubed::tcubed() {
}

tcubed::~tcubed() {
}

void tcubed::init_game() {
	// For now, we are not allocating any resources,
	// nor are we creating the board.  We are just
	// setting our start game state.
	_gamestate = _game_menu_;
}

void tcubed::get_input();	//gives control to the player -> calls make move the player whose turn it is.
void tcubed::render() {
	switch (_gamestate) {
		case _game_active_:
			renderGameBoard(_mygameboard);
			break;
		case _player_1_victory_:
			renderVictory(_player1);
			renderGameMenu();
			break;
		case _player_2_victory_:
			renderVictory(_player2);
			renderGameMenu();
			break;
		case _stalemate_:
			renderStalemate();
			renderGameMenu();
			break;
		case _game_menu_:
			renderGameMenu();
			break;
		default:
	}
};	

void tcubed::renderGameBoard(gameboard board) {
	// Lame board render
	board.printBoard();
}

void tcubed::renderVictory(player p) {
	// Lame stalemate render, for the moment
	cout << "WINNER: " << p.get_piece() << endl;
}

void tcubed::renderStalemate() {
	// Lame stalemate render, for the moment
	cout << "WINNER: NONE" << endl;
}

void tcubed::renderGameMenu() {
	// Lame menu render, for the moment
	cout << "T^3" << endl;
	cout << endl;
	cout << "Please choose an option: " << endl;
	cout << "  1. Play two-player game" << endl;
	cout << "  2. Play one-player game (vs. AI)" << endl;
	cout << "  3. Quit" << endl;
}

int tcubed::get_game_state() {
	return _gamestate;
}

gameboard _mygameboard;	//the game that's being played