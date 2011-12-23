#include <iostream>
#include "gameboard.h"

using namespace std;

gameboard::gameboard() {
	// Create a game board with all blank spaces
	resetBoard();
}

gameboard::~gameboard() {
	// Nothing to do here--we did not dynamically allocate any memory
}

void gameboard::resetBoard() {
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 3; i++) {
			board[j][i] = ' ';
		}
	}
}

void gameboard::printBoard() {
	// For now, just printing chars (not pretty)
	cout << " A B C" << endl;
	for (int j = 0; j < 3; j++) {
		cout << (j + 1);
		for (int i = 0; i < 3; i++) {
			char separator = '\|';
			if (i == 2) { separator = ' '; }
			cout << board[j][i] << separator;
		}
		cout << endl;
		if (j != 2) {
			cout << " -+-+-" << endl;
		}
	}
}

bool gameboard::placepiece(char piece, int x_loc, int y_loc) {
	bool placedPiece = false;
	// Todo: We may want to change placepiece to throw errors on invalid inputs, later
	if (isValidLocation(x_loc, y_loc)) {
		board[y_loc][x_loc] = piece;
		placedPiece = true;
	}

	return placedPiece;
}

bool gameboard::isValidLocation(int x_loc, int y_loc) {
	bool result = true;
	// Ensure we're within the appropriate bounds
	if ((x_loc < 0) || (x_loc > 2)) {
		result = false;
	}
	if ((y_loc < 0) || (y_loc > 2)) {
		result = false;
	}
	// Ensure space is not already occupied
	if (board[y_loc][x_loc] != ' ') {
		result = false;
	}

	return result;
}

char gameboard::getPiece(int x_loc, int y_loc) {
	// TODO: Let's just assume x and y are valid, for now.  Should throw exception if not.
	return board[y_loc][x_loc];
}