#include "Queen.h"
#include "Piece.h"

Queen::Queen(string color) {
	this->color = color;
	this->type = QUEEN;
}

char Queen::format() {
	return (this->color == WHITE ? 'Q' : 'q');
}