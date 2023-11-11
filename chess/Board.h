#include "Piece.h"
#include "Empty.h"
#pragma once
class Board {
public:
	Piece* grid[8][8];
	int turnCount = 1;
	Piece* lastPieceMoved = new Empty();
	vector<string> moveHistory;
	Board(); // default constructor for Board (fills grid with starting layout)
	Piece* getPieceAtPosition(int row, int col); // returns the Piece the given row x col
	void print(); // prints the current board
	void printLine(int row); // helper function for print()
	void move(int startRow, int startCol, int endRow, int endCol);
	void getInput();
	string checkMove(string input, int startRow, int startCol, int endRow, int endCol);
	void printErrorMessage(string error);
	string getCurrentTurn();
};

