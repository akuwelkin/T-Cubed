#ifndef _TCUBED
#define _TCUBED

#include "player.h"
#include "gameboard.h"

class tcubed
{
public:
	tcubed();  // constructor
	~tcubed(); // destructor
	void play_game();

private:
	
	void init_game(char multiplayer);
	void get_input();	//gives control to the player -> calls make move the player whose turn it is.
	void render();	//outputs gameboard to stout;
	int get_game_state();	//returns the game state

	player* _player1;
	player* _player2;

	gameboard _mygameboard;	//the game that's being played
	bool isplayer1turn;

	int _gamestate;	//the gamestate of the game

	void setGameState(int newState); // sets the game state to the specified state
	void evaluateGameEnd(); // checks to see if the game is over; updates state accordingly
	void renderGameMenu(); // renders the game menu
	void renderVictory(player p); // renders victory for a player
	void renderStalemate(); // renders stalemate
	void renderGameBoard(gameboard board); // renders the board

	char getRowWinner(int y_loc);
	char getColWinner(int x_loc);
	char getDiagonalsWinner();

		//possible game states
	static const int _game_active_ = 0;
	static const int _player_1_victory_ = 1;
	static const int _player_2_victory_ = 2;
	static const int _stalemate_ = 3;
	static const int _game_menu_ = 4;
	static const int _game_quit_ = 5;

	static const char _menu_2player = '1';
	static const char _menu_1player = '2';
	static const char _menu_quit = '3';
};

#endif