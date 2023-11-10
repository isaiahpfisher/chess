#include "header.h"
#pragma once
class Piece {
public:
	char type;
	string color; // color (WHITE, BLACK)
	Piece(); // default constructor
	Piece(char type, string color);
	bool isEmpty(); // check if Piece is empty
	string getPossibleMoves(); // this is just a random function I was experimenting with
};