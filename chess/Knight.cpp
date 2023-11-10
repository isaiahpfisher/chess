#include "Knight.h"
#include "Piece.h"

Knight::Knight(string color) {
	this->color = color;
	this->type = KNIGHT;
}

char Knight::format() {
	return (this->color == WHITE ? 'N' : 'n');
}