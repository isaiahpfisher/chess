#include "Pawn.h"
#include "Piece.h"

Pawn::Pawn(string color) {
	this->color = color;
	this->type = PAWN;
}

bool Pawn::isValidMove(Piece* grid[8][8], int startRow, int startCol, int endRow, int endCol) {
	return true;
}