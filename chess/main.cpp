#include "header.h"
#include "Pawn.h"
#include "Piece.h"
#include "Board.h"

/*
 - If you run main() right now, you should see a board printed with the starting layout, except for one pawn moved two spaces forward.
 - It's ugly, but it's a starting point.
 - Black pieces are represented by CAPITAL letters, and white pieces are represented by lowercase letters.
 - Kings are represented with K's and Knights are represented with N's.
*/

int main() {

    Board game; // game has a game.grid property that holds an 8x8 array filled with the right pieces for game start

    
    // simulating moving left-most black pawn to spaces forward
    game.grid[1][0] = Piece(); // sets pawn's current location to empty
    game.grid[3][0] = Piece(PAWN, BLACK); // sets pawn's new location to two spaces forward


    game.print(); // prints the game.grid, pieces and all

    return 0;
}
