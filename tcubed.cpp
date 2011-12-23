#include <iostream>
#include "tcubed.h"

using namespace std;

tcubed::tcubed() {
	_player1 = NULL;
	_player2 = NULL;
}

tcubed::~tcubed() {
}

void tcubed::init_game(char multiplayer) {
	//multiplayer == _menu_1player define 1 human 1 AI
	//multiplayer == _menu_2player define 2 human

	// For now, we are not allocating any resources,
	// nor are we creating the board.  We are just
	// setting our start game state.
	_gamestate = _game_menu_;
}

//Game loop
void tcubed::play_game()
{
	






}

//void tcubed::get_input();	//gives control to the player -> calls make move the player whose turn it is.
void tcubed::render() {
	switch (_gamestate) {
		case _game_active_:
			renderGameBoard(_mygameboard);
			break;
		case _player_1_victory_:
			renderVictory(*_player1);
			renderGameMenu();
			break;
		case _player_2_victory_:
			renderVictory(*_player2);
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


//gives control to the player -> calls make move the player whose turn it is.
void tcubed::get_input()
{
	char input;
	//based on gamestate act accordingly
	switch(_gamestate)
	{
	case _game_menu_:
		renderGameMenu();
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
		renderVictory(*_player1);
		_gamestate = _game_menu_;
		break;
	case _player_2_victory_:
		renderVictory(*_player2);
		_gamestate = _game_menu_;
		break;
	case _stalemate_:
		renderStalemate();
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
	// stub
}