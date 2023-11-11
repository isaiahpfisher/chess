#include "Queen.h"
#include "Piece.h"

Queen::Queen(string color) {
	this->color = color;
	this->type = QUEEN;
}

string Queen::isValidMove(Board* game, int startRow, int startCol, int endRow, int endCol) {
	return "true";
}