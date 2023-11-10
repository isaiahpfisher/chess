#include "King.h"
#include "Piece.h"

King::King(string color) {
	this->color = color;
	this->type = KING;
}

bool King::isValidMove(Piece* grid[8][8], int startRow, int startCol, int endRow, int endCol) {
	return true;
}