#include "Piece.h"
#include "Empty.h"
#include "King.h"
#pragma once
class Board {
public:
	Board(); // default constructor for Board (fills grid with starting layout)
	Board(Board* original);
	Piece* grid[8][8];
	int turnCount = 1;
	Piece* lastPieceMoved = new Empty();
	Piece* whiteKing = new Empty();
	Piece* blackKing = new Empty();
	int turnSinceLastTake = 0;
	vector<string> history = { "base" };
	vector<MoveHistory> moveHistory;
	vector<MoveHistory> getTakenPieces(string color);
	Piece* getPieceAtPosition(int row, int col); // returns the Piece the given row x col
	void print(); // prints the current board
	void printLine(int row, vector<MoveHistory> whiteTaken, vector<MoveHistory> blackTaken); // helper function for print()
	string translateCoordinates(int row, int col);
	void translateMoveHistory(MoveHistory move);
	void move(int startRow, int startCol, int endRow, int endCol);
	void getInput();
	string checkMove(string currentTurn, string input, int startRow, int startCol, int endRow, int endCol);
	void printErrorMessage(string error);
	string getCurrentTurn();
	bool isCheckmate();
	bool isOver();
	bool isStalemate();
	bool isMate();
	string boardToString();
	bool isThirdRepetition();
	bool isInsufficientMaterial();
	bool gameEndMenu();
	void titleScreen();
	double evaluateBoard(string color);
	int countPieces(char type, string color);
	int countDoubledPawns(string color);
	int countIsolatedPawns(string color);
	int countBlockedPawns(string color);
	int countTotalLegalMoves(string color);
	void doComputerMove(int levels);
	bool isAI = false;
};

