#include "King.h"
#include "Piece.h"

King::King(string color) {
	this->color = color;
	this->type = KING;
}

string King::isValidMove(Piece* grid[8][8], int startRow, int startCol, int endRow, int endCol) {
	string checkResult;

	int rowDiff = abs(startRow - endRow);
	int colDiff = abs(startCol - endCol);

	// moved non-linearly
	if ((rowDiff != colDiff) && !(rowDiff == 0 || colDiff == 0)) {
		checkResult = "Kings can only move linearly. Try Again.";
	}
	// moved more than one space
	else if (rowDiff > 2 || colDiff > 2) {
		checkResult = "Kings can only move one space at a time.";
	}

	return checkResult;
}

string King::move(Piece* grid[8][8], int startRow, int startCol, int endRow, int endCol) {
	return "";
}