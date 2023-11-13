#include "Pawn.h"
#include "Empty.h"
#include "Piece.h"
#include "Rook.h"
#include "Bishop.h"
#include "Queen.h"
#include "Knight.h"

Pawn::Pawn(string color, bool isAI) {
	this->color = color;
	this->type = PAWN;
	this->isAI = isAI;
	this->unicode = u8"\u265F";
}

// checks if move is a valid move for a pawn
string Pawn::isValidMove(Piece* grid[8][8], int startRow, int startCol, int endRow, int endCol) {
	string checkResult;
	int direction = (this->color == WHITE ? WHITE_DIRECTION : BLACK_DIRECTION);
	
	// moved more than one column to the side
	if ((abs(startCol - endCol) > 1) || (abs(startCol - endCol) > 0 && abs(startRow - endRow) > 1)) {
		checkResult = "You SiCkO!!!!! Why are you trying to move that way. Try Again.";
	}
	// tried to go backwards
	else if ((endRow * direction < startRow * direction)) {
		checkResult = "Pawns can't move backwards. Try Again.";
	}
	// tried to move sideways
	else if (startRow == endRow) {
		checkResult = "Pawns can't move sideways. Try Again.";
	}
	// tried to move more than one/two spaces forward
	else if (abs(startRow - endRow) > 1 + !this->hasMoved) {
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

	string moveResult;
	int direction = (this->color == WHITE ? WHITE_DIRECTION : BLACK_DIRECTION);

	// if en passant happened, remove the enemy piece
	if (grid[endRow - direction][endCol]->enPassant) {
		delete grid[endRow - direction][endCol]; // THIS COULD BE THE SOURCE OF A BUG
		grid[endRow - direction][endCol] = new Empty();
		moveResult = "En Passant";
	}

	// if pawn moved two spaces (which is only possible on first turn), make it vulnerable to en passant attack
	if (abs(startRow - endRow) == 2) {
		this->enPassant = true;
	}

	// so this pawn can't move two ever again
	this->row = endRow;
	this->col = endCol;
	this->hasMoved = true;

	// 
	if (endRow == (this->color == WHITE ? 0 : 7)) {
		getPawnPromotion(grid);
	}
	return moveResult;
}

// 
void Pawn::getPawnPromotion(Piece* grid[8][8]) {

	char userChoice;
	

	cout << endl;
	cout << " >> " << " Pawn Promotion: what would you like?" << endl;
	cout << " >>  Q for Queen, R for Rook, B for Bishop, and N for Knight" << endl;
	cout << " >>  ";
	if (!this->isAI) {
		cin >> userChoice;
		userChoice = toupper(userChoice);
		cin.ignore();
	}
	else {
		userChoice = 'Q';
	}
	switch (userChoice) {
	case ('Q'):
		grid[this->row][this->col] = new Queen(this->color);
		break;
	case ('R'):
		grid[this->row][this->col] = new Rook(this->color);
		break;
	case ('B'):
		grid[this->row][this->col] = new Bishop(this->color);
		break;
	case ('N'):
		grid[this->row][this->col] = new Knight(this->color);
		break;
	default:
		cout << endl << endl << endl;
		getPawnPromotion(grid);
		break;
	}
}

// 
bool Pawn::isInCheck(Piece* grid[8][8], int startRow, int startCol, int endRow, int endCol) {
	return false;
}