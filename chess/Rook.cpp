#include "Rook.h"
#include "Piece.h"

Rook::Rook(string color) {
	this->color = color;
	this->type = ROOK;
}

char Rook::format() {
	return (this->color == WHITE ? 'R' : 'r');
}