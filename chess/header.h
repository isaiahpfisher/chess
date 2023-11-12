#ifndef HEADER_H
#define HEADER_H
#pragma once

// Included Files
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <Windows.h>

using namespace std;

// Constant Declarations
const char KING = 'K';
const char QUEEN = 'Q';
const char ROOK = 'R';
const char KNIGHT = 'N';
const char BISHOP = 'B';
const char PAWN = 'P';
const char EMPTY = 'E';
const string WHITE = "RED";
const string BLACK = "PURPLE";
const string EMPTY_COLOR = "EMPTY";
const int WHITE_TURN = 1;
const int BLACK_TURN = 0;
const int WHITE_DIRECTION = -1;
const int BLACK_DIRECTION = 1;
const int CELL_SIZE = 6;

// Structs Definitions
struct MoveHistory {
	int startRow, startCol, endRow, endCol;
	char startType;
	string startColor, startUnicode;
	char endType;
	string endColor, endUnicode;
	bool enPassant;
	bool castled;
};

// Function Declarations

#endif