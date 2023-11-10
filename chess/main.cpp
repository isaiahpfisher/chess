#include "header.h"
#include "Pawn.h"
#include "Piece.h"
#include "Board.h"

int main() {

    Board game; // game has a game.grid property that holds an 8x8 array filled with the right pieces for game start

    
    // simulating moving left-most black pawn to spaces forward
    game.grid[1][0] = Piece(); // sets current location of pawn to empty
    game.grid[3][0] = Piece(PAWN, BLACK);


    game.print(); // prints the game.grid, pieces and all

    return 0;
}
