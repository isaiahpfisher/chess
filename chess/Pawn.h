#include "header.h"
#include "Piece.h"

#pragma once
class Pawn : public Piece { 
public:
	Pawn(string color); // custom constructor
	bool canMoveTwo = true;
	string isValidMove(Board* game, int startRow, int startCol, int endRow, int endCol);

};

