#include "Knight.h"
#include "Piece.h"

Knight::Knight(string color) {
	this->color = color;
	this->type = KNIGHT;
}

bool Knight::isValidMove(Piece* grid[8][8], int startRow, int startCol, int endRow, int endCol) {
	return true;
}