#include "King.h"
#include "Piece.h"

King::King(string color) {
	this->color = color;
	this->type = KING;
}

char King::format() {
	return (this->color == WHITE ? 'K' : 'k');
}