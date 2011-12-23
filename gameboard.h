#ifndef _GAMEBOARD
#define _GAMEBOARD

class gameboard
{
public:
	gameboard();  // constructor
	~gameboard(); // destructor
	bool placepiece (char piece, int x_loc, int y_loc);
	void printBoard();
	
private:
	bool isValidLocation(int x_loc, int y_loc);

	char board[3][3];
};

#endif