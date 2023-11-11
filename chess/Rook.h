#include "header.h"
#include "Piece.h"
#pragma once
class Rook : public Piece {
public:
	Rook(string color); // custom constructor
	string isValidMove(Board* game, int startRow, int startCol, int endRow, int endCol);
};

