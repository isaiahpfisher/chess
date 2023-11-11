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

// translate x,y coordinates to a string for moveHistory
string Piece::translateMoves(int row, int col) {
	string strCol(1, col + 'A');
	string strRow(1, 8 - row + '0');
	return strCol + strRow;

	/*startCol = toupper(input[0]) - 'A';
	startRow = 8 - (input[1] - '0');
	endCol = toupper(input[3]) - 'A';
	endRow = 8 - (input[4] - '0');*/
}


bool Piece::isPieceInWay(Piece* grid[8][8], int startRow, int startCol, int endRow, int endCol) {

	bool checkResult = false;

	int maxRow = (startRow > endRow ? startRow : endRow);
	int minRow = (startRow < endRow ? startRow : endRow);
	int maxCol = (startCol > endCol ? startCol : endCol);
	int minCol = (startCol < endCol ? startCol : endCol);


	// moving front to back
	if (minRow != maxRow && minCol == maxCol) {
		for (int row = 0; row < 8; row++) {
			for (int col = 0; col < 8; col++) {
				if (col == minCol && row > minRow && row < maxRow) {
					if (!grid[row][col]->isEmpty()) {
						checkResult = true;
					}
				}
			}
		}
	}
	// side to side
	else if (minRow == maxRow && minCol != maxCol) {
		for (int row = 0; row < 8; row++) {
			for (int col = 0; col < 8; col++) {
				if (row == minRow && col > minCol && col < maxCol) {
					if (!grid[row][col]->isEmpty()) {
						checkResult = true;
					}
				}
			}
		}
	}
	// diagonal moves
	else {
		for (int row = 0; row < 8; row++) {
			for (int col = 0; col < 8; col++) {
				if (((row > minRow && row < maxRow) && (col > minCol && col < maxCol)) && (abs(row - startRow) == abs(col - startCol))) {
					if (!grid[row][col]->isEmpty()) {
						checkResult = true;
					}
				}
			}
		}
	}

	if (this->type == KNIGHT) { checkResult = false; }
	
	return checkResult;
}