#include "Queen.h"
#include "Piece.h"

Queen::Queen(string color) {
	this->color = color;
	this->type = QUEEN;
}

string Queen::isValidMove(Piece* grid[8][8], int startRow, int startCol, int endRow, int endCol) {
	string checkResult;

	int rowDiff = abs(startRow - endRow);
	int colDiff = abs(startCol - endCol);

	// moved non-linearly
	if ((rowDiff != colDiff) &&  !(rowDiff == 0 || colDiff == 0)) {
		checkResult = "Queens can only move linearly. Try Again.";
	}

	return checkResult;
}

string Queen::move(Piece* grid[8][8], int startRow, int startCol, int endRow, int endCol) {
	return "";
}

bool Queen::isInCheck(Piece* grid[8][8], int startRow, int startCol, int endRow, int endCol) {
	return false;
}