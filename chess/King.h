#include "header.h"
#include "Piece.h"

#pragma once
class King : public Piece {
public:
	int row;
	int col;
	King(string color, int row, int col); // custom constructor
	string isValidMove(Piece* grid[8][8], int startRow, int startCol, int endRow, int endCol);
	string move(Piece* grid[8][8], int startRow, int startCol, int endRow, int endCol);
	bool isInCheck(Piece* grid[8][8], int startRow, int startCol, int endRow, int endCol);
};