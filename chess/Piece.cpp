#include "Piece.h"
#include "Pawn.h"
#include "Rook.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Empty.h"

// default constructor - this is what empty spaces on the board will have
Piece::Piece() {
	this->type = EMPTY;
}

// constructor
Piece::Piece(char type, string color) {
	this->type = type;
	this->color = color;
}

// to check if a space on the board is empty (every element in the Board.grid always has a Piece in it, but it has a special value if empty
bool Piece::isEmpty() {
	return this->type == EMPTY;
}

string Piece::translateMoves(int row, int col) {
	string strCol(1, col + 'A');
	string strRow(1, 8 - row + '0');
	return strCol + strRow;

	/*startCol = toupper(input[0]) - 'A';
	startRow = 8 - (input[1] - '0');
	endCol = toupper(input[3]) - 'A';
	endRow = 8 - (input[4] - '0');*/
}