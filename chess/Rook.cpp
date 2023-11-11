#include "Rook.h"
#include "Piece.h"

Rook::Rook(string color) {
	this->color = color;
	this->type = ROOK;
}

string Rook::isValidMove(Board* game, int startRow, int startCol, int endRow, int endCol) {
	return "true";
}