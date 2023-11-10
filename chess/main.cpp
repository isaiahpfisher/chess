#include "header.h"
#include "Pawn.h"
#include "Piece.h"
#include "Board.h"
#include "Empty.h"

/*
 - If you run main() right now, you should see a board printed with the starting layout, except for one pawn moved two spaces forward.
 - It's ugly, but it's a starting point.
 - White pieces are represented by CAPITAL letters, and black pieces are represented by lowercase letters.
 - Kings are represented with K's and Knights are represented with N's.
*/

int main() {

    Board game; // game has a game.grid property that holds an 8x8 array filled with the right pieces for game start


    game.print(); // prints the game.grid, pieces and all

    game.getInput();

    game.print();

    return 0;
}
