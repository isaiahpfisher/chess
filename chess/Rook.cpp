#include "Rook.h"
#include "Piece.h"

Rook::Rook(string color) {
	this->color = color;
	this->type = ROOK;
	this->unicode = u8"\u265C";
}

string Rook::isValidMove(Piece* grid[8][8], int startRow, int startCol, int endRow, int endCol) {
	string checkResult;
	
	if (startCol != endCol && startRow != endRow) {
		checkResult = "Rook can't move diagonally. Try Again.";
	}

	return checkResult;
}

string Rook::move(Piece* grid[8][8], int startRow, int startCol, int endRow, int endCol) {
	 
	this->row = endRow;
	this->col = endCol;

	this->hasMoved = true;

	return "";
}

bool Rook::isInCheck(Piece* grid[8][8], int startRow, int startCol, int endRow, int endCol) {
	return false;
}