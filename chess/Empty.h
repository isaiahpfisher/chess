#include "header.h"
#include "Piece.h"
#pragma once
class Empty : public Piece {
public:
	char type = EMPTY;
	char format();
};

