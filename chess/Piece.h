#include "header.h"
#pragma once
class Piece {
public:
	char type;
	string color; // color (WHITE, BLACK)
	Piece(); // default constructor
	Piece(char type, string color);
	bool isEmpty(); // check if Piece is empty
	char format(); // returns a char representing the piece, either upper or lower depending on color
	string getPossibleMoves(); // this is just a random function I was experimenting with
};