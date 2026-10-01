#include <iostream>
#include "RPG.h"
using namespace std;

int main()
{
    RPG p1 = RPG("Wiz", 0, 0.2, 60, 1);
    RPG p2 = RPG();

    printf("%s Current Stats\n", p1.getName().c_str());
    printf("Hits Taken: %i\t Luck: %f\t Exp: %f\t Level: %i\n", p1.getHitsTaken(), p1.getLuck(), p1.getExp(), p1.getLevel());

    // print the same for p2
    printf("%s Current Stats\n", p2.getName().c_str());
    printf("Hits Taken: %i\t Luck: %f\t Exp: %f\t Level: %i\n", p2.getHitsTaken(), p2.getLuck(), p2.getExp(), p2.getLevel());

    // call setHitsTaken(new_hit) on either p1 and p2
    // print out hits_taken
    int random = (rand() % 2) + 1;
    if (random == 1){
        cout << "\nP1 Hit";
        p1.setHitsTaken(p1.getHitsTaken() + 1);
    } else{
        cout << "\nP2 Hit";
        p2.setHitsTaken(p2.getHitsTaken() + 1);
    }

    cout << "\n0 is dead, 1 is alive";
    // call isAlive() on both p1 and p2
    p1.isAlive();
    p2.isAlive();

    return 0;
}