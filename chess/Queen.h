#include "header.h"
#include "Piece.h"
#pragma once
class Queen : public Piece {
public:
	Queen(string color); // custom constructor
	string isValidMove(Board* game, int startRow, int startCol, int endRow, int endCol);
};

