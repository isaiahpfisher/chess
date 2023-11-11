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
	this->grid[0][3] = new Queen(BLACK);
	this->grid[0][4] = new King(BLACK, 0, 4);
	this->blackKing = this->grid[0][4];
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
	this->grid[7][3] = new Queen(WHITE);
	this->grid[7][4] = new King(WHITE, 7, 4);
	this->whiteKing = this->grid[7][4];
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
	Piece* startPiece = this->getPieceAtPosition(startRow, startCol);

	// make the move
	delete grid[endRow][endCol];
	grid[endRow][endCol] = grid[startRow][startCol];
	grid[startRow][startCol] = new Empty();

	// do move-specific code and push move to move history
	this->moveHistory.push_back(startPiece->move(this->grid, startRow, startCol, endRow, endCol));
	
	// reset enPassant of previous piece
	lastPieceMoved->enPassant = false;

	// set lastPieceMoved to current piece
	lastPieceMoved = this->grid[endRow][endCol];


	// Check if checkmate
}

// Gets the input for moves
void Board::getInput() {
	string input;
	int startRow, startCol, endRow, endCol;
	cout << " >> " << (this->getCurrentTurn() == WHITE ? dye::red(WHITE) : dye::purple(BLACK))
		<< ": What's your next move? (ex. A3 B5  or  a3 b5)" << endl << " >> ";
	getline(cin, input);

	// makes sure input is long enough
	if (input.length() < 5) {
		print();
		printErrorMessage("Invalid input (" + input + "). Too short. Try Again.");
		getInput();
		return;
	}

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
	if (input != "-1" && (startCol < 0 || startCol > 7 || startRow < 0 || startRow > 7 || endCol < 0 || endCol > 7 || endRow < 0 || endRow > 7)) {
		checkResult = "Invalid Move (" + input + "). Try Again.";
	}

	// Check if startPiece is invalid
	else if (startPiece->isEmpty()) {
		checkResult = "No piece at first coordinate. Try Again.";
	}

	// Check if startPiece is from the right team
	else if (this->getCurrentTurn() != startPiece->color) {
		checkResult = "It's " + (this->getCurrentTurn() == WHITE ? WHITE : BLACK) + "'s turn. Try Again.";
	}

	// Checks if move is on top of same team
	else if (startPiece->color == endPiece->color) {
		checkResult = "Can't move on top of own piece. Try Again.";
	}
	// checking if piece is in the way
	else if (startPiece->isPieceInWay(this->grid, startRow, startCol, endRow, endCol)) {
		checkResult = "Can't jump over piece. Try Again.";
	}
	// checking if piece can do that move
	else if (checkResult == "") {
		checkResult = startPiece->isValidMove(this->grid, startRow, startCol, endRow, endCol);
	}
	// checking for check
	if (checkResult == "") {
		Piece* currentKing = (this->getCurrentTurn() == WHITE ? whiteKing : blackKing);
		string inCheckResult;
		if (currentKing->isInCheck(this->grid, -1, -1, -1, -1)) {
			inCheckResult = "You're king is in check. Try Again.";
		}
		else if (currentKing->isInCheck(this->grid, startRow, startCol, endRow, endCol)) {
			inCheckResult = "You can't put your king in check. Try Again.";
		}
		if (currentKing->isInCheck(this->grid, startRow, startCol, endRow, endCol)) {
			checkResult = inCheckResult;
		}
	}

	return checkResult;
}

// Prints the error message is wrong move or does the move is valid
void Board::printErrorMessage(string error) {
	cout << " >> " << dye::white_on_red(" " + error + " ") << endl;
}

// returns the color of whatever team's turn it is
string Board::getCurrentTurn() {
	return (turnCount % 2 == WHITE_TURN ? WHITE : BLACK);
}

bool Board::isCheckmate() {
	string currentColor = this->getCurrentTurn();
	Piece* currentKing = (this->getCurrentTurn() == WHITE ? whiteKing : blackKing);

	// return false if king isn't in check at start of turn
	if (!currentKing->isInCheck(this->grid, -1, -1, -1, -1)) { return false; }


	// check for any possible moves that won't make the king in check
	for (int row = 0; row < 8; row++) {
		for (int col = 0; col < 8; col++) {
			Piece* piece = this->getPieceAtPosition(row, col);
			if (!piece->isEmpty() && piece->color == currentColor) {
				for (int subRow = 0; subRow < 8; subRow++) {
					for (int subCol = 0; subCol < 8; subCol++) {
						if (this->checkMove("-1", row, col, subRow, subCol) == "" && !currentKing->isInCheck(this->grid, row, col, subRow, subCol)) {
							return false; // return false at first sign of a move that wouldn't put the king in check
						}
					}
				}
			}
		}
	}
	return true;
}