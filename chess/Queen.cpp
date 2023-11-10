#include "Queen.h"
#include "Piece.h"

Queen::Queen(string color) {
	this->color = color;
	this->type = QUEEN;
}

bool Queen::isValidMove(Piece* grid[8][8], int startRow, int startCol, int endRow, int endCol) {
	return true;
}