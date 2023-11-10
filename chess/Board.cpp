#include "Board.h"
#include "color.hpp"
#include "Piece.h"
#include "Pawn.h"
#include "Rook.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Empty.h"

// initializes the grid of the board to have the starting positions of a chess game
Board::Board() {

	// Black First Row
	this->grid[0][0] = new Rook(BLACK);
	this->grid[0][1] = new Knight(BLACK);
	this->grid[0][2] = new Bishop(BLACK);
	this->grid[0][3] = new King(BLACK);
	this->grid[0][4] = new Queen(BLACK);
	this->grid[0][5] = new Bishop(BLACK);
	this->grid[0][6] = new Knight(BLACK);
	this->grid[0][7] = new Rook(BLACK);

	// Black Second Row
	this->grid[1][0] = new Pawn(BLACK);
	this->grid[1][1] = new Pawn(BLACK);
	this->grid[1][2] = new Pawn(BLACK);
	this->grid[1][3] = new Pawn(BLACK);
	this->grid[1][4] = new Pawn(BLACK);
	this->grid[1][5] = new Pawn(BLACK);
	this->grid[1][6] = new Pawn(BLACK);
	this->grid[1][7] = new Pawn(BLACK);

	// Empty Spaces
	for (int row = 2; row < 6; row++) {
		for (int col = 0; col < 8; col++) {
			this->grid[row][col] = new Empty();
		}
	}

	// White First Row
	this->grid[7][0] = new Rook(WHITE);
	this->grid[7][1] = new Knight(WHITE);
	this->grid[7][2] = new Bishop(WHITE);
	this->grid[7][3] = new King(WHITE);
	this->grid[7][4] = new Queen(WHITE);
	this->grid[7][5] = new Bishop(WHITE);
	this->grid[7][6] = new Knight(WHITE);
	this->grid[7][7] = new Rook(WHITE);

	// White Second Row
	this->grid[6][0] = new Pawn(WHITE);
	this->grid[6][1] = new Pawn(WHITE);
	this->grid[6][2] = new Pawn(WHITE);
	this->grid[6][3] = new Pawn(WHITE);
	this->grid[6][4] = new Pawn(WHITE);
	this->grid[6][5] = new Pawn(WHITE);
	this->grid[6][6] = new Pawn(WHITE);
	this->grid[6][7] = new Pawn(WHITE);
}

// prints the board
void Board::print() {
	cout << "    ";
	for (char letter = 65; letter < 73; letter++) {
		cout << "  " << letter << "   ";
	}

	cout << endl << endl;

	for (int row = 0; row < 8; row++) {
		printLine(row);
	}
}

// prints a single row of the board
void Board::printLine(int row) {
	for (int subRow = 0; subRow < CELL_SIZE / 2; subRow++) {

		if (subRow == (CELL_SIZE / 4)) {
			cout << (row + 1) << "   ";
		} else {
			cout << "    ";
		}

		for (int col = 0; col < 8; col++) {
			for (int subCol = 0; subCol < CELL_SIZE; subCol++) {
				if ((row + col) % 2 == 0) {
					if (!(*getPieceAtPosition(row, col)).isEmpty() && (subRow == (CELL_SIZE / 4) && subCol == CELL_SIZE / 2 - 1)) {
						if (getPieceAtPosition(row, col)->color == WHITE) {
							cout << dye::red_on_white(getPieceAtPosition(row, col)->type);
						} else {
							cout << dye::purple_on_white(getPieceAtPosition(row, col)->type);
						}
					} else {
						cout << dye::on_white(" ");
					}
				}
				else {
					if (!(*getPieceAtPosition(row, col)).isEmpty() && (subRow == (CELL_SIZE / 4) && subCol == CELL_SIZE / 2 - 1)) {
						if (getPieceAtPosition(row, col)->color == WHITE) {
							cout << dye::red_on_black(getPieceAtPosition(row, col)->type);
						} else {
							cout << dye::purple_on_black(getPieceAtPosition(row, col)->type);
						}
					} else {
						cout << dye::on_black(" ");
					}
				}
			}
		}
		cout << endl;
	}
}

// returns the Piece at the given position
Piece* Board::getPieceAtPosition(int row, int col) {
	return this->grid[row][col];
}

// moves a piece on the board
void Board::move(int startRow, int startCol, int endRow, int endCol) {

	// get pieces/spaces
	Piece* startPiece = this->getPieceAtPosition(startRow, startCol);
	Piece* endPiece = this->getPieceAtPosition(endRow, endCol);

	// check if startPiece is empty (which would be invalid)
	if (startPiece->isEmpty()) {
		cout << endl << "There's no piece at those starting coordinates";
		return;
	}

	if (!endPiece->isEmpty()) {
		cout << endl << "There's already a piece at those ending coordinates";
		return;
	}

	delete this->grid[endRow][endCol];
	this->grid[endRow][endCol] = startPiece;
	this->grid[startRow][startCol] = new Empty();


	

}
