#include "Bishop.h"
#include "Piece.h"

Bishop::Bishop(string color) {
	this->color = color;
	this->type = BISHOP;
}

char Bishop::format() {
	return (this->color == WHITE ? 'B' : 'b');
}