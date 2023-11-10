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
	bool isEmpty = false;
	Empty* empty = dynamic_cast<Empty*>(this);
	if (empty) { isEmpty = true; }
	delete empty;
	return isEmpty;
}

// WIP - just a filler function for how I'm (Isaiah) thinking things will be set up
string Piece::getPossibleMoves() {
	switch (this->type) {
		case KING:
			return "King's Moves";
		case QUEEN:
			return "Queen's Moves";
		case ROOK:
			return "Rook's Moves";
		case KNIGHT:
			return "Knight's Moves";
		case BISHOP:
			return "Bishop's Moves";
		case PAWN:
			return "Pawn's Moves";
		default:
			return "Error";
	}
}