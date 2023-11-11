#include "header.h"
#include "Piece.h"
#pragma once
class Rook : public Piece {
public:
	Rook(string color); // custom constructor
	string isValidMove(Piece* grid[8][8], int startRow, int startCol, int endRow, int endCol);
	string move(Piece* grid[8][8], int startRow, int startCol, int endRow, int endCol);
};

