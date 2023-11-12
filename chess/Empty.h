#include "header.h"
#include "Piece.h"
#pragma once
class Empty : public Piece {
public:
	char type = EMPTY;
	string color = EMPTY_COLOR;
	string isValidMove(Piece* grid[8][8], int startRow, int startCol, int endRow, int endCol);
	string move(Piece* grid[8][8], int startRow, int startCol, int endRow, int endCol);
	bool isInCheck(Piece* grid[8][8], int startRow, int startCol, int endRow, int endCol);
};