#ifndef _GAMEBOARD
#define _GAMEBOARD

class gameboard
{
public:
	char board[3][3];

	bool placepiece (char piece, int x_loc, int y_loc);

	gameboard();	//constructor

};

#endif