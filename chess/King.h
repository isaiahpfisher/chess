#include "header.h"
#include "Piece.h"

#pragma once
class King : public Piece {
public:
	King(string color); // custom constructor
	string isValidMove(Board* game, int startRow, int startCol, int endRow, int endCol);
};