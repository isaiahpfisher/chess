#include "Piece.h"
#pragma once
class Board {
public:
	Piece* grid[8][8];
	Board(); // default constructor for Board (fills grid with starting layout)
	Piece getPieceAtPosition(int row, int col); // returns the Piece the given row x col
	void print(); // prints the current board
	void printLine(int row); // helper function for print()
};

