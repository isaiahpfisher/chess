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
	
	system("cls");

	cout << endl << endl;

	for (int row = 0; row < 8; row++) {
		printLine(row);
	}

	cout << endl;
	cout << "      ";
	for (char letter = 'A'; letter <= 'H'; letter++) {
		cout << "  " << letter << "   ";
	}
	cout << endl << endl;
}

// prints a single row of the board
void Board::printLine(int row) {
	for (int subRow = 0; subRow < CELL_SIZE / 2; subRow++) {

		if (subRow == (CELL_SIZE / 4)) {
			cout << "  " << (8 - row) << "   ";
		} else {
			cout << "      ";
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

	delete this->grid[endRow][endCol];
	this->grid[endRow][endCol] = startPiece;
	this->grid[startRow][startCol] = new Empty();

	// Check if check or checkmate
	// Check if a piece can move to the spot chosen
	// check if move is on same team
	// en passant and castling
	// first move of pawn
	// pawn promotion
	
	print();
}

// Gets the input for moves
void Board::getInput() {
	string input;
	int startRow, startCol, endRow, endCol;
	cout << "What's your next move? (ex. A3 B5  or  a3 b5)" << endl;
	getline(cin, input);
	startCol = toupper(input[0]) - 'A';
	startRow = 8 - (input[1] - '0');
	endCol = toupper(input[3]) - 'A';
	endRow = 8 - (input[4] - '0');
	
	string checkResult = checkMove(input, startRow, startCol, endRow, endCol);
	if (checkResult == "") {
		move(startRow, startCol, endRow, endCol);
	}
	else {
		print();
		printErrorMessage(checkResult);
		getInput();
	}
}

// Checks if moves are valid
string Board::checkMove(string input, int startRow, int startCol, int endRow, int endCol){
	
	// get pieces/spaces
	Piece* startPiece = this->getPieceAtPosition(startRow, startCol);
	Piece* endPiece = this->getPieceAtPosition(endRow, endCol);
	string checkResult; // What the error message will say, blank if valid

	// Checks if the move is on the board
	if (startCol < 0 || startCol > 7 || startRow < 0 || startRow > 7 || endCol < 0 || endCol > 7 || endRow < 0 || endRow > 7) {
		checkResult = "Invalid Move (" + input + "). Try Again.";
	}

	// Check if startPiece is invalid
	else if (startPiece->isEmpty()) {
		checkResult = "No piece at first coordinate. Try Again.";
	}

	// Check if startPiece is from the right team
	else if (getCurrentTurn() != startPiece->color) {
		checkResult = "It's " + (getCurrentTurn() == WHITE ? WHITE : BLACK) + "'s turn. Try Again.";
	}

	// Checks if move is on top of same team
	else if (startPiece->color == endPiece->color) {
		checkResult = "Can't move on top of own piece. Try Again.";
	}

	return checkResult;

	// Check if check or checkmate
	// Check if a piece can move to the spot chosen
	// en passant and castling
	// first move of pawn
	// pawn promotion
	// check if it is red or purples move.
}

// Prints the error message is wrong move or does the move is valid
void Board::printErrorMessage(string error) {
	cout << dye::white_on_red(" " + error + " ") << endl;
}

// returns the color of whatever team's turn it is
string Board::getCurrentTurn() {
	return (turnCount % 2 == WHITE_TURN ? WHITE : BLACK);
}