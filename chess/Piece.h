#include "header.h"

#pragma once
class Piece {
public:
	char type;
	string color; // color (WHITE, BLACK)
	bool enPassant = false;
	Piece(); // default constructor
	Piece(char type, string color);
	bool isEmpty(); // check if Piece is empty
	string translateMoves(int row, int col);
	virtual string isValidMove(Piece* grid[8][8], int startRow, int startCol, int endRow, int endCol) = 0;
	virtual string move(Piece* grid[8][8], int startRow, int startCol, int endRow, int endCol) = 0;
};