#ifndef CHARMANDER_H
#define CHARMANDER_H

#include <string>
#include <vector>
#include "Pokemon.h"
using namespace std;

class Charmander : public Pokemon{
    public:
        //constructors
        Charmander();
        Charmander(string name, int hp, int att, int def, vector<string> t, vector<string> s);
        //mutators
        virtual void speak();
        virtual void printStats();
    
    protected:
        vector<string> skills;
};

#endif