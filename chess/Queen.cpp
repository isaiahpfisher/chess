#include "Queen.h"
#include "Piece.h"

Queen::Queen(string color) {
	this->color = color;
	this->type = QUEEN;
	this->unicode = u8"\u265B";
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
	
	this->row = endRow;
	this->col = endCol;
	this->hasMoved = true;
	return "";
}

bool Queen::isInCheck(Piece* grid[8][8], int startRow, int startCol, int endRow, int endCol) {
	return false;
}