#include "King.h"
#include "Piece.h"

King::King(string color) {
	this->color = color;
	this->type = KING;
}

string King::isValidMove(Piece* grid[8][8], int startRow, int startCol, int endRow, int endCol) {
	return "true";
}

string King::move(Piece* grid[8][8], int startRow, int startCol, int endRow, int endCol) {
	return "";
}