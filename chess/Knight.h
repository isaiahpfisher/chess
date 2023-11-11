#include "header.h"
#include "Piece.h"

#pragma once
class Knight : public Piece {
public:
	Knight(string color); // custom constructor
	string isValidMove(Board* game, int startRow, int startCol, int endRow, int endCol);
};