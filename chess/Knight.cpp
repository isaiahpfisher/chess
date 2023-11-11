#include "Knight.h"
#include "Piece.h"

Knight::Knight(string color) {
	this->color = color;
	this->type = KNIGHT;
}

string Knight::isValidMove(Piece* grid[8][8], int startRow, int startCol, int endRow, int endCol) {
	return "true";
}

string Knight::move(Piece* grid[8][8], int startRow, int startCol, int endRow, int endCol) {
	return "";
}