#ifndef _PLAYER
#define _PLAYER

#include "gameboard.h"

class player
{
public:
	void makemove(gameboard& playarea_);	//places a move onto the gameboard
	player(char set_piece);
	char get_piece();
	void set_piece(char set_piece);

private:
	int convertInputToIndex(char input_);
	char _piece;
};

#endif