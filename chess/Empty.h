#include "header.h"
#include "Piece.h"
#pragma once
class Empty : public Piece {
public:
	char type = EMPTY;
	string isValidMove(Board* game, int startRow, int startCol, int endRow, int endCol);
};