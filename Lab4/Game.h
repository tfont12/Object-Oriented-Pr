#ifndef GAME_H
#define GAME_H
#include "RPG.h"
#include <string>
#include <vector>
#include <set>
using namespace std;

class Game{
    public:
        // constructors
        Game();

        // functions
        void generatePlayers(int n);
        int selectPlayer();
        void endRound(RPG* winner, RPG* loser, int loserIndex);
        void battleRound();
        void gameLoop();
        void printFinalResults() const;

    private:
        vector<RPG*> players;
        set<int> live_players;
};

#endif