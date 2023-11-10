#include "header.h"
#include "Piece.h"
#pragma once
class Rook : public Piece {
public:
	string color;
	Rook(string color); // custom constructor
	char format(); // returns a char representing the piece, either upper or lower depending on color
};

