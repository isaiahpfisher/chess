#include "header.h"
#include "Piece.h"
#pragma once
class Empty : public Piece {
public:
	char type = EMPTY;
	char format(); // returns a char representing the piece, either upper or lower depending on color
};

