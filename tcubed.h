#ifndef _TCUBED
#define _TCUBED

#include "player.h"
#include "gameboard.h"

class tcubed
{
public:
	void play_game();

private:
	
	void init_game();
	void get_input();	//gives control to the player -> calls make move the player whose turn it is.
	void render();	//outputs gameboard to stout;
	int get_game_state();	//returns the game state

	player _player1;
	player _player2;

	gameboard _mygameboard;	//the game that's being played
	bool isplayer1turn;

	int _gamestate;	//the gamestate of the game


		//possible game states
	static const int _game_active_ = 0;
	static const int _player_1_victory_ = 1;
	static const int _player_2_victory_ = 2;
	static const int _stalemate_ = 3;
	static const int _game_menu_ = 4;
};

#endif