#include "Piece.h"
#pragma once
class Board {
public:
	Piece grid[8][8];
	Board();
	Piece getPieceAtPosition(int row, int col);
	void print();
	void printLine(int row);
	void printCell(int row, int col);
	void printCell(Piece piece, int row, int col);
};

