#include "Board.h"
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
	for (int row = 0; row < 8; row++) {
		printLine(row);
	}
}

// prints a single row of the board
void Board::printLine(int row) {
	for (int subRow = 0; subRow < CELL_SIZE / 2; subRow++) {
		for (int col = 0; col < 8; col++) {
			for (int subCol = 0; subCol < CELL_SIZE; subCol++) {
				if (!(*getPieceAtPosition(row, col)).isEmpty() && (subRow == (CELL_SIZE / 4) && subCol == CELL_SIZE / 2 - 1)) {
					cout << getPieceAtPosition(row, col)->format();
				}
				else {
					cout << char((row + col) % 2 == 0 ? WHITE_SQUARE : BLACK_SQUARE);
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

void Board::move(int startRow, int startCol, int endRow, int endCol) {

}
