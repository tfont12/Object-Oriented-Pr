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

void Game::battleRound(){
    // call selectPlayer twice and assign the values to playerIndex1 and playerIndex2
    int playerIndex1 = selectPlayer();
    int playerIndex2 = selectPlayer();

    // if index 1 = index 2, call battleRound() again and return
    if (playerIndex1 == playerIndex2){
        battleRound();
        return;
    }

    // create two RPG * called player 1 and player 2 using  players[playerIndex]
    RPG* player1 = players[playerIndex1];
    RPG* player2 = players[playerIndex2];

    // while both players are alive call player1->attack(player2) and vice versa
    while (player1->isAlive()==true && player2->isAlive() == true){
        player1->attack(player2);
        player2->attack(player1);
    }

    // outside of the while loop, identify which player is alive
    // call endRound with for the correct respective players

    if (player1->isAlive()){
        endRound(player1,player2,playerIndex2);
    } else if (player2->isAlive()){
        endRound(player2,player1,playerIndex1);
    }
}

// run battleRound() until there is only 1 player alive
void Game::gameLoop(){
    while(live_players.size() > 1){
        battleRound();
    }
}

// call printstats on all players
void Game::printFinalResults(){
    for(int i=0;i<players.size();i++){
        players[i]->printStats();
    }
}

// deconstructor
Game::~Game(){}