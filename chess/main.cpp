#include "header.h"
#include "Board.h"
#include "Empty.h"


int main() {

    bool playAgain = true;

    // 
    while (playAgain) {
        Board game; // game has a game.grid property that holds an 8x8 array filled with the right pieces for game start

        // 
        while (!game.isOver()) {
            game.print(); // prints the game.grid, pieces and all
            game.getInput(); // asks for and receives input
            game.turnCount++; // keep track of turn with count (odd red, even = purple)
        }

        playAgain = game.gameEndMenu();
    }
    return 0;
}