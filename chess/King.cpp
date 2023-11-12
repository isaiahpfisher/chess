#include "King.h"
#include "Piece.h"
#include "Empty.h"

// 
King::King(string color, int row, int col) {
	this->color = color;
	this->type = KING;
	this->unicode = u8"\u265A";
	this->row = row;
	this->col = col;
}

// 
string King::isValidMove(Piece* grid[8][8], int startRow, int startCol, int endRow, int endCol) {
	string checkResult;

	int rowDiff = abs(startRow - endRow);
	int colDiff = abs(startCol - endCol);

	// where rook SHOULD be
	int rookRow = (this->color == BLACK ? 0 : 7);
	int rookCol = (endCol < startCol ? 0 : 7);
	Piece* rookSpot = grid[rookRow][rookCol];

	// the spot the king passes through
	int midRow = (this->color == BLACK ? 0 : 7);
	int midCol = (endCol < startCol ? 3 : 5);

	// moved non-linearly
	if ((rowDiff != colDiff) && !(rowDiff == 0 || colDiff == 0)) {
		checkResult = "Kings can only move linearly. Try Again.";
	}
	// castling
	else if (colDiff == 2 && rowDiff == 0) {
		// if either piece has already moved
		if (this->hasMoved || (rookSpot->type == ROOK && rookSpot->hasMoved)) {
			checkResult = "Can't castle if king or rook has already moved. Try Again.";
		}
		// any pieces between them
		else if (endCol < startCol && !grid[rookRow][rookCol + 1]->isEmpty()) {
			checkResult = "Can't castle if there are pieces in the way. Try Again.";
		}
		// currently in check
		else if (this->isInCheck(grid, -1, -1, -1, -1)) {
			checkResult = "Kings can't castle to get out of check. Try Again.";
		}
		// pass through a check
		else if (this->isInCheck(grid, startRow, startCol, midRow, midCol)) {
			checkResult = "Kings can't castle through a check. Try Again.";
		}
	}
	// moved more than one space
	else if (rowDiff > 1 || colDiff > 1) {
		checkResult = "Kings can only move one space at a time. Try Again.";
	}

	return checkResult;
}

// 
string King::move(Piece* grid[8][8], int startRow, int startCol, int endRow, int endCol) {

	int rowDiff = abs(startRow - endRow);
	int colDiff = abs(startCol - endCol);

	// get the rook
	int rookRow = (this->color == BLACK ? 0 : 7);
	int rookCol = (endCol < startCol ? 0 : 7);

	// rook destination
	int rookRowDest = (this->color == BLACK ? 0 : 7);
	int rookColDest = (endCol < startCol ? endCol + 1 : endCol - 1);

	// if castling, move the rook
	if (colDiff == 2) {
		delete grid[rookRowDest][rookColDest];
		grid[rookRowDest][rookColDest] = grid[rookRow][rookCol];
		grid[rookRow][rookCol] = new Empty();
	}

	this->row = endRow;
	this->col = endCol;
	this->hasMoved = true;

	return "";
}

// 
bool King::isInCheck(Piece* grid[8][8], int startRow, int startCol, int endRow, int endCol) {

	bool isInCheck = false;
	Piece* endPiece = nullptr;

	if (startRow != -1 && startCol != -1 && endRow != -1 && endCol != -1) {
		if (grid[startRow][startCol]->type == KING) {
			this->row = endRow;
			this->col = endCol;
		}
		endPiece = grid[endRow][endCol];
		grid[endRow][endCol] = grid[startRow][startCol];
		grid[startRow][startCol] = new Empty();
	}

	for (int row = 0; row < 8; row++) {
		for (int col = 0; col < 8; col++) {
			Piece* piece = grid[row][col];
			if (!piece->isEmpty() && piece->color != this->color) {
				string checkResult = piece->isValidMove(grid, row, col, this->row, this->col); 
				bool inWay = piece->isPieceInWay(grid, row, col, this->row, this->col);
				if (checkResult == "" && !inWay) {
					isInCheck = true;
				}
			}
		}
	}

	if (startRow != -1 && startCol != -1 && endRow != -1 && endCol != -1) {
		delete grid[startRow][startCol];
		grid[startRow][startCol] = grid[endRow][endCol];
		grid[endRow][endCol] = endPiece;
		if (grid[startRow][startCol]->type == KING) {
			this->row = startRow;
			this->col = startCol;
		}
	}

	return isInCheck;
}