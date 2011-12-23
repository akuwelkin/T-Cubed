#include "player.h"
#include <iostream>
#include <string>

using namespace std;

//This fuction works from input to adding the piece to the gameboard with a valid move
//This class currently expects a human player
	void player::makemove(gameboard& playarea_)
	{
		//get input for move
		
		string inputline;
		int x_index, y_index;

		while(true)
		{
			cout<<"Please enter your next move in the format [letter][number]\n"
				<<"Example: A1, B2, etc.\n"
				<<"Input:";
			cin>>inputline;

			if(inputline[0] >= '0' && inputline[0] <= '2')
			{	//check incase they input y_index first
				x_index = convertInputToIndex(inputline[1]);
				y_index = convertInputToIndex(inputline[0]);
			}
			else
			{
				x_index = convertInputToIndex(inputline[0]);
				y_index = convertInputToIndex(inputline[1]);
			}


			//check if valid move
			if(x_index >= 0 && y_index >= 0)
			{	//if both valid indexii
				if(playarea_.placepiece(get_piece(),x_index,y_index))
				{	//if the piece successfully places
					return;
				}
			}

			cout<<"Invalid move, please try again:";

		}
			return;
	}

	//-1 is bad input
	//1 or A returns 0
	//2 or B return 1
	//3 or C return 2;
	int player::convertInputToIndex(char input_)
	{
		switch(input_)
		{
		case 'a': case 'A': case '1':
			return 0;
		case 'b': case'B': case'2':
			return 1;
		case 'c': case 'C': case '3':
			return 2;
		default:
			return -1;
		}
		return -1;
	}

	//CONSTRUCTOR
	player::player(char set_piece)
	{
		_piece = set_piece;
	}

	//GET AND SET FOR _PIECE
	char player::get_piece()
	{
		return _piece;
	}
	void player::set_piece(char set_piece)
	{
		_piece = set_piece;
	}