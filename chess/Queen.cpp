#include "Queen.h"
#include "Piece.h"

Queen::Queen(string color) {
	this->color = color;
	this->type = QUEEN;
}

string Queen::isValidMove(Piece* grid[8][8], int startRow, int startCol, int endRow, int endCol) {
	return "true";
}

string Queen::move(Piece* grid[8][8], int startRow, int startCol, int endRow, int endCol) {
	return "";
}