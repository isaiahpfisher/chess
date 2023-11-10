#include "Bishop.h"
#include "Piece.h"

Bishop::Bishop(string color) {
	this->color = color;
	this->type = BISHOP;
}

bool Bishop::isValidMove(Piece* grid[8][8], int startRow, int startCol, int endRow, int endCol) {
	return true;
}