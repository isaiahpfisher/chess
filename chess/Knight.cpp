#include "Knight.h"
#include "Piece.h"

Knight::Knight(string color) {
	this->color = color;
	this->type = KNIGHT;
}

string Knight::isValidMove(Board* game, int startRow, int startCol, int endRow, int endCol) {
	return "true";
}