#include "Board.h"
#include "Piece.h"
#include "Pawn.h"
#include "Rook.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"

// initializes the grid of the board to have the starting positions of a chess game
Board::Board() {

	// Black First Row
	this->grid[0][0] = &Rook(BLACK);
	this->grid[0][1] = &Knight(BLACK);
	this->grid[0][2] = &Bishop(BLACK);
	this->grid[0][3] = &King(BLACK);
	this->grid[0][4] = &Queen(BLACK);
	this->grid[0][5] = &Bishop(BLACK);
	this->grid[0][6] = &Knight(BLACK);
	this->grid[0][7] = &Rook(BLACK);

	// Black Second Row
	this->grid[1][0] = &Pawn(BLACK);
	this->grid[1][1] = &Pawn(BLACK);
	this->grid[1][2] = &Pawn(BLACK);
	this->grid[1][3] = &Pawn(BLACK);
	this->grid[1][4] = &Pawn(BLACK);
	this->grid[1][5] = &Pawn(BLACK);
	this->grid[1][6] = &Pawn(BLACK);
	this->grid[1][7] = &Pawn(BLACK);

	// White First Row
	this->grid[7][0] = &Rook(WHITE);
	this->grid[7][1] = &Knight(WHITE);
	this->grid[7][2] = &Bishop(WHITE);
	this->grid[7][3] = &King(WHITE);
	this->grid[7][4] = &Queen(WHITE);
	this->grid[7][5] = &Bishop(WHITE);
	this->grid[7][6] = &Knight(WHITE);
	this->grid[7][7] = &Rook(WHITE);

	// White Second Row
	this->grid[6][0] = &Pawn(WHITE);
	this->grid[6][1] = &Pawn(WHITE);
	this->grid[6][2] = &Pawn(WHITE);
	this->grid[6][3] = &Pawn(WHITE);
	this->grid[6][4] = &Pawn(WHITE);
	this->grid[6][5] = &Pawn(WHITE);
	this->grid[6][6] = &Pawn(WHITE);
	this->grid[6][7] = &Pawn(WHITE);
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
				if (!getPieceAtPosition(row, col).isEmpty() && (subRow == (CELL_SIZE / 4) && subCol == CELL_SIZE / 2 - 1)) {
					cout << getPieceAtPosition(row, col).format();
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
Piece Board::getPieceAtPosition(int row, int col) {
	return this->grid[row][col];
}
