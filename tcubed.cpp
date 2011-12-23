#include <iostream>
#include <stdlib.h>
#include "tcubed.h"

using namespace std;

tcubed::tcubed() {
	_player1 = NULL;
	_player2 = NULL;

	_gamestate = _game_menu_;	//prompt for menu first
}

tcubed::~tcubed() {
}

void tcubed::init_game(char multiplayer) {
	//multiplayer == _menu_1player define 1 human 1 AI
	//multiplayer == _menu_2player define 2 human
	_player1 = new player('X');
	_player2 = new player('O');

	// For now, we are not allocating any resources,
	// nor are we creating the board.  We are just
	// setting our start game state.
	_gamestate = _game_menu_;
}

//Game loop
void tcubed::play_game()
{
	while(_gamestate != _game_quit_)
	{
		render();	//outputs the appropriate information
		get_input();	//this function updates the gamestate
	}
}

//void tcubed::get_input();	//gives control to the player -> calls make move the player whose turn it is.
void tcubed::render() {
	system("cls");
	switch (_gamestate) {
		case _game_active_:
			renderGameBoard(_mygameboard);
			break;
		case _player_1_victory_:
			renderVictory(*_player1);
			break;
		case _player_2_victory_:
			renderVictory(*_player2);
			break;
		case _stalemate_:
			renderStalemate();
			break;
		case _game_menu_:
			renderGameMenu();
			break;
		default:
			break;
	}
}

void tcubed::renderGameBoard(gameboard board) {
	// Lame board render
	board.printBoard();
}

void tcubed::renderVictory(player p) {
	// Lame stalemate render, for the moment
	cout << "WINNER: " << p.get_piece() << endl;
	renderGameBoard(_mygameboard);
}

void tcubed::renderStalemate() {
	// Lame stalemate render, for the moment
	cout << "WINNER: NONE" << endl;
	renderGameBoard(_mygameboard);
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


//gives control to the player -> calls make move the player whose turn it is.
void tcubed::get_input()
{
	char input;
	//based on gamestate act accordingly
	switch(_gamestate)
	{
	case _game_menu_:
		cin>>input;

		if(input == _menu_2player)
		{
			init_game(_menu_2player);
			_gamestate = _game_active_;
		}
		else if (input == _menu_1player)
		{
			init_game(_menu_1player);
			_gamestate = _game_active_;
		}
		else if (input == _menu_quit)
		{
			cout<<"Sad to see you leave =( =(\n";
			_gamestate = _game_quit_;
		}
		else
		{
			cout<<"Invalid input\n";
		}
		break;

	case _player_1_victory_:
		_gamestate = _game_menu_;
		break;
	case _player_2_victory_:
		_gamestate = _game_menu_;
		break;
	case _stalemate_:
		_gamestate = _game_menu_;
		break;
	case _game_active_:
		if(isplayer1turn)
		{	//if player 1 turn, ask player 1 to move
			_player1->makemove(_mygameboard);
		}
		else
		{	//otherwise ask player 2
			_player2->makemove(_mygameboard);
		}
		isplayer1turn = !isplayer1turn;
		evaluateGameEnd();
		break;
	case _game_quit_:
		cout<<"You should have quit already\n";
		break;
	default:
		cout<<"Error!!!! Invalid Gamestate: "<<_gamestate;
		_gamestate = _game_menu_;
	}
}

void tcubed::setGameState(int newState) {
	// Todo: validation of input would be wise
	_gamestate = newState;
}

void tcubed::evaluateGameEnd() {
	if (_gamestate != _game_active_) {
		return; // No game is in progress
	}
	char player1Char = _player1->get_piece();
	char player2Char = _player2->get_piece();

	char winner = 0;

	// TODO: Should be refactored for single-point-of-return later
	for (int j = 0; j < 3; j++) {
		if (getRowWinner(j) != '\0') {
			winner = getRowWinner(j);
			if (player1Char == winner) {
				setGameState(_player_1_victory_);
				return;
			} else {
				setGameState(_player_2_victory_);
				return;
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		if (getColWinner(i) != '\0') {
			winner = getColWinner(i);
			if (player1Char == winner) {
				setGameState(_player_1_victory_);
				return;
			} else {
				setGameState(_player_2_victory_);
				return;
			}
		}
	}
	if (getDiagonalsWinner() != '\0') {
		winner = getDiagonalsWinner();
		if (player1Char == winner) {
			setGameState(_player_1_victory_);
			return;
		} else {
			setGameState(_player_2_victory_);
			return;
		}
	}

	// Check for stalemate
	bool stalemate = true;
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 3; i++) {
			if (_mygameboard.getPiece(i,j) == ' ') {
				stalemate = false;
			}
		}
	}
	if (stalemate) {
		setGameState(_stalemate_);
	}
}

char tcubed::getRowWinner(int y_loc) {
	int x_loc = 0;
	char pieceToCheck = _mygameboard.getPiece(x_loc,y_loc);
	bool isVictory = false;
	int counter = 1;
	x_loc++;
	while ((x_loc < 3) && (pieceToCheck != ' ') && (_mygameboard.getPiece(x_loc,y_loc) == pieceToCheck)) {
		counter++;
		x_loc++;
	}
	if (counter == 3) {
		isVictory = true;
	}
	return isVictory ? pieceToCheck : '\0';
}

char tcubed::getColWinner(int x_loc) {
	int y_loc = 0;
	char pieceToCheck = _mygameboard.getPiece(x_loc,y_loc);
	bool isVictory = false;
	int counter = 1;
	y_loc++;
	while ((y_loc < 3) && (pieceToCheck != ' ') && (_mygameboard.getPiece(x_loc,y_loc) == pieceToCheck)) {
		counter++;
		y_loc++;
	}
	if (counter == 3) {
		isVictory = true;
	}
	return isVictory ? pieceToCheck : '\0';
}

char tcubed::getDiagonalsWinner() {
	int x_loc = 0;
	int y_loc = 0;
	char pieceToCheck = _mygameboard.getPiece(x_loc,y_loc);
	bool isVictory = false;
	int counter = 1;
	x_loc++;
	y_loc++;
	while ((x_loc < 3) && (pieceToCheck != ' ') && (_mygameboard.getPiece(x_loc,y_loc) == pieceToCheck)) {
		counter++;
		x_loc++;
		y_loc++;
	}
	if (counter == 3) {
		return pieceToCheck; // ULTRA UGLY -- should refactor this =)
	}

	x_loc = 2;
	y_loc = 0;
	pieceToCheck = _mygameboard.getPiece(x_loc,y_loc);
	isVictory = false;
	counter = 1;
	x_loc--;
	y_loc++;
	while ((x_loc > 0) && (pieceToCheck != ' ') && (_mygameboard.getPiece(x_loc,y_loc) == pieceToCheck)) {
		counter++;
		x_loc--;
		y_loc++;
	}
	if (counter == 3) {
		isVictory = true; // ULTRA UGLY -- should refactor this =)
	}

	return isVictory ? pieceToCheck : '\0';
}