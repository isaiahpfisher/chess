#include "Board.h"
#include "Piece.h"

// initializes the grid of the board to have the starting positions of a chess game
Board::Board() {

	// Black First Row
	this->grid[0][0] = Piece(ROOK, BLACK);
	this->grid[0][1] = Piece(KNIGHT, BLACK);
	this->grid[0][2] = Piece(BISHOP, BLACK);
	this->grid[0][3] = Piece(KING, BLACK);
	this->grid[0][4] = Piece(QUEEN, BLACK);
	this->grid[0][5] = Piece(BISHOP, BLACK);
	this->grid[0][6] = Piece(KNIGHT, BLACK);
	this->grid[0][7] = Piece(ROOK, BLACK);

	// Black Second Row
	this->grid[1][0] = Piece(PAWN, BLACK);
	this->grid[1][1] = Piece(PAWN, BLACK);
	this->grid[1][2] = Piece(PAWN, BLACK);
	this->grid[1][3] = Piece(PAWN, BLACK);
	this->grid[1][4] = Piece(PAWN, BLACK);
	this->grid[1][5] = Piece(PAWN, BLACK);
	this->grid[1][6] = Piece(PAWN, BLACK);
	this->grid[1][7] = Piece(PAWN, BLACK);

	// White First Row
	this->grid[7][0] = Piece(ROOK, WHITE);
	this->grid[7][1] = Piece(KNIGHT, WHITE);
	this->grid[7][2] = Piece(BISHOP, WHITE);
	this->grid[7][3] = Piece(KING, WHITE);
	this->grid[7][4] = Piece(QUEEN, WHITE);
	this->grid[7][5] = Piece(BISHOP, WHITE);
	this->grid[7][6] = Piece(KNIGHT, WHITE);
	this->grid[7][7] = Piece(ROOK, WHITE);

	// White Second Row
	this->grid[6][0] = Piece(PAWN, WHITE);
	this->grid[6][1] = Piece(PAWN, WHITE);
	this->grid[6][2] = Piece(PAWN, WHITE);
	this->grid[6][3] = Piece(PAWN, WHITE);
	this->grid[6][4] = Piece(PAWN, WHITE);
	this->grid[6][5] = Piece(PAWN, WHITE);
	this->grid[6][6] = Piece(PAWN, WHITE);
	this->grid[6][7] = Piece(PAWN, WHITE);
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

// returns the piece at the given position
Piece Board::getPieceAtPosition(int row, int col) {
	return this->grid[row][col];
}
