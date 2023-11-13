#include "header.h"
#include "Board.h"
#include "Empty.h"

int main() {
    
    SetConsoleOutputCP(CP_UTF8);

    bool playAgain = true;

    // 
    while (playAgain) {
        Board game; // game has a game.grid property that holds an 8x8 array filled with the right pieces for game start

  

        game.titleScreen();

        // 
        while (!game.isOver()) {
            if (!game.isAI || game.turnCount % 2 == 1) {
                game.print(); // prints the game.grid, pieces and all
            }

            if (game.isAI && game.turnCount % 2 == 0) {
                game.doComputerMove();
            }
            else {
                game.getInput(); // asks for and receives input
            }

            game.turnCount++; // keep track of turn with count (odd red, even = purple)
        }

        playAgain = game.gameEndMenu();
    }
    return 0;
}