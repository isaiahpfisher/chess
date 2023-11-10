#include "Pawn.h"
#include "Piece.h"

Pawn::Pawn(string color) {
	this->color = color;
	this->type = PAWN;
}

char Pawn::format() {
	return (this->color == WHITE ? 'P' : 'p');
}