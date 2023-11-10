#include "header.h"
#pragma once
class Piece {
public:
	char type; // type (KING, QUEEN, etc.)
	string color; // color (WHITE, BLACK)
	Piece();
	Piece(char type, string color);
	bool isEmpty();
	char format();
	string getPossibleMoves();
};

