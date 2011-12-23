#include <iostream>
#include "gameboard.h"

gameboard::gameboard() {
	// Create a game board with all blank spaces
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 3; i++) {
			board[j][i] = ' ';
		}
	}
}

gameboard::~gameboard() {
	// Nothing to do here--we did not dynamically allocate any memory
}

void gameboard::printBoard() {

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