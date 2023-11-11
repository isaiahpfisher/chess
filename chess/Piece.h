#include "header.h"
#include "Board.h"

#pragma once
class Piece {
public:
	char type;
	string color; // color (WHITE, BLACK)
	bool enPassant = false;
	Piece(); // default constructor
	Piece(char type, string color);
	bool isEmpty(); // check if Piece is empty
	string getPossibleMoves(); // this is just a random function I was experimenting with
	virtual string isValidMove(Board* game, int startRow, int startCol, int endRow, int endCol) = 0;
};