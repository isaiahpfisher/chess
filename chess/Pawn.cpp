#include "Pawn.h"
//#include "Piece.h"

Pawn::Pawn(string color) {
	this->color = color;
	this->type = PAWN;
}

string Pawn::isValidMove(Board* game, int startRow, int startCol, int endRow, int endCol) {
	string checkResult;
	int direction = (this->color == WHITE ? WHITE_DIRECTION : BLACK_DIRECTION);

	if (!(endRow * direction > startRow * direction) && (startCol == endCol)) {
		checkResult = "Pawn can't go backwards. Try Again.";
	}
	else if (!(startCol == endCol)
		&& !((abs(startRow - endRow) == 1 && abs(startCol - endCol) == 1 && !game->grid[endRow][endCol]->isEmpty()))
		&& !(game->lastPieceMoved->enPassant) && abs(startRow - endRow) == 1 && abs(startCol - endCol) == 1) {
		checkResult = "Pawn can only move forward unless taking enemy piece. Try Again.";
	}
	else if (!(abs((startRow - endRow)) <= 1 + this->canMoveTwo)) { // checks if it has moved two forwards
		checkResult = "Pawn can't move that many spaces. Try Again.";
	}
	else if ((startCol == endCol) && !game->grid[endRow][endCol]->isEmpty()) {
		checkResult = "Pawn can only take an enemy diagonally. Try Again.";
	}
	
	if (checkResult == "") {
		this->canMoveTwo = false;
	}

	if (abs(startCol - endCol) == 2) {
		this->enPassant = true;
	}

	return checkResult;
}

// set enPassant = false after one turn