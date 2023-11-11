#include "King.h"
#include "Piece.h"

King::King(string color) {
	this->color = color;
	this->type = KING;
}

string King::isValidMove(Board* game, int startRow, int startCol, int endRow, int endCol) {
	return "true";
}