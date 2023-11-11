#include "Empty.h"
#include "Piece.h"

string Empty::isValidMove(Piece* grid[8][8], int startRow, int startCol, int endRow, int endCol) {
	return "";
}

string Empty::move(Piece* grid[8][8], int startRow, int startCol, int endRow, int endCol) {
	
	this->row = endRow;
	this->col = endCol;

	return "";
}

bool Empty::isInCheck(Piece * grid[8][8], int startRow, int startCol, int endRow, int endCol) {
	return false;
}