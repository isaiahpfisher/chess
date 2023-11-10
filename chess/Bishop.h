#include "header.h"
#include "Piece.h"

#pragma once
class Bishop : public Piece {
public:
	Bishop(string color); // custom constructor
	bool isValidMove(Piece* grid[8][8], int startRow, int startCol, int endRow, int endCol);
};