#include "Bishop.h"
#include "Piece.h"

Bishop::Bishop(string color) {
	this->color = color;
	this->type = BISHOP;
}

string Bishop::isValidMove(Board* game, int startRow, int startCol, int endRow, int endCol) {
	return "";
}