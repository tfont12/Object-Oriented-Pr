#include <iostream>
#include "RPG.h"
#include "Game.h"
using namespace std;

int main()
{
    // Create a game object
    Game game = Game();
    // Create num_players as an int and set it to 10
    int num_players = 10;
    // Call generatePlayers() with num_players as the parameter
    game.generatePlayers(num_players);
    // Call gameLoop()
    game.gameLoop();
    // Call printFinalResults()
    game.printFinalResults();

    return 0;
}