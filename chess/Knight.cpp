#include "Knight.h"
#include "Piece.h"

Knight::Knight(string color) {
	this->color = color;
	this->type = KNIGHT;
}

string Knight::isValidMove(Piece* grid[8][8], int startRow, int startCol, int endRow, int endCol) {
	string checkResult;
	int direction = (this->color == WHITE ? WHITE_DIRECTION : BLACK_DIRECTION);

	int rowDiff = abs(startRow - endRow);
	int colDiff = abs(startCol - endCol);

	if ((startRow == endRow) || (startCol == endCol) || (rowDiff + colDiff != 3)) {
		checkResult = "Knights can't move that way. Try Again.";
	}

	return checkResult;
}

string Knight::move(Piece* grid[8][8], int startRow, int startCol, int endRow, int endCol) {
	return "";
}

bool Knight::isInCheck(Piece* grid[8][8], int startRow, int startCol, int endRow, int endCol) {
	return false;
}
