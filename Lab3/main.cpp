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

    // call setHitsTaken(new_hit) on either p1 and p2

    cout << "\nP2 hits taken";
    // print out hits_taken

    cout << "0 is dead, 1 is alive\n";
    // call isAlive() on both p1 and p2

    return 0;
}