#include "Game.h"
#include <string>
#include <random>
#include <set>

// constructor
Game::Game(){}

// functions

void Game::generatePlayers(int n){
    for(int i=0;i<n;i++){
        players.push_back(new RPG());

        //rename players
        string new_name = "NPC_"+to_string(i);
        players[i]->setName(new_name);
        live_players.insert(i);
    }
}

int Game::selectPlayer(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, live_players.size() - 1);

    // pick random index
    int random_index = dist(gen);

    // advance iterator to that index
    set<int>::iterator it = live_players.begin();
    advance(it, random_index);

    int selectedIndex = *it;
    return selectedIndex;

}

void Game::endRound(RPG *winner, RPG *loser, int loserIndex){
    // set winner hits taken to 0 and update exp level
    winner->setHitsTaken(0);
    winner->updateExpLevel();

    // remove loser from live players
    set<int>::iterator it = live_players.begin();
    advance(it, loserIndex);
    live_players.erase(it);

    // print
    printf("%s\t won against %s\t\n", winner->getName().c_str(), loser->getName().c_str());
}