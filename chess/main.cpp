#include "header.h"
#include "Board.h"
#include "Empty.h";


int main() {
    // keep track of turn with count (odd red, even = purple)

    Board game; // game has a game.grid property that holds an 8x8 array filled with the right pieces for game start

    while (game.turnCount <= 20) {
        game.print(); // prints the game.grid, pieces and all
        game.getInput(); // asks for and receives input
        game.turnCount++;
    }

    return 0;
}
