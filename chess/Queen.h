#include "header.h"
#include "Piece.h"
#pragma once
class Queen : public Piece {
	string color;
	Queen(string color); // custom constructor
	char format(); // returns a char representing the piece, either upper or lower depending on color
};

