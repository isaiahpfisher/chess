#include "header.h"
#include "Piece.h"

#pragma once
class Bishop : public Piece {
public:
	Bishop(string color); // custom constructor
	string isValidMove(Board* game, int startRow, int startCol, int endRow, int endCol);
};