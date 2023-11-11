#include "Pawn.h"
#include "Empty.h"

Pawn::Pawn(string color) {
	this->color = color;
	this->type = PAWN;
}

// checks if move is a valid move for a pawn
string Pawn::isValidMove(Piece* grid[8][8], int startRow, int startCol, int endRow, int endCol) {
	string checkResult;
	int direction = (this->color == WHITE ? WHITE_DIRECTION : BLACK_DIRECTION);

	// tried to go backwards
	if ((endRow * direction < startRow * direction) && (startCol == endCol)) {
		checkResult = "Pawns can't move backwards. Try Again.";
	}
	// tried to move sideways
	else if (startRow == endRow) {
		checkResult = "Pawns can't move sideways. Try Again.";
	}
	// tried to move more than one/two spaces forward
	else if (abs(startRow - endRow) > 1 + this->canMoveTwo) {
		checkResult = "Pawns can't move that many spaces. Try Again.";
	}
	// tried to move forward into enemny
	else if ((startCol == endCol) && !grid[endRow][endCol]->isEmpty()) {
		checkResult = "Pawns can only take an enemy diagonally. Try Again.";
	}
	// tried to move diagonallly (without taking enemy or en passant)
	else if ((startCol != endCol) && (grid[endRow][endCol]->isEmpty()) && !(grid[endRow - direction][endCol]->enPassant)) {
		checkResult = "Pawns can't move diagonally unless taking enemy. Try Again.";
	}


	return checkResult;
}

// performs pawn-specific actions after a move
string Pawn::move(Piece* grid[8][8], int startRow, int startCol, int endRow, int endCol) {

	string moveResult = translateMoves(startRow, startCol) + " to " + translateMoves(endRow, endCol);
	int direction = (this->color == WHITE ? WHITE_DIRECTION : BLACK_DIRECTION);

	// if en passant happened, remove the enemy piece
	if (grid[endRow - direction][endCol]->enPassant) {
		grid[endRow - direction][endCol] = new Empty();
	}

	// if pawn moved two spaces (which is only possible on first turn), make it vulnerable to en passant attack
	if (abs(startRow - endRow) == 2) {
		this->enPassant = true;
	}

	// so this pawn can't move two ever again
	this->canMoveTwo = false;

	return moveResult;
}

bool Pawn::isInCheck(Piece* grid[8][8], int startRow, int startCol, int endRow, int endCol) {
	return false;
}

// need to finish writing moveResult;