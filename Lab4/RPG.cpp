// RPG.cpp
#include "RPG.h"
#include<string>
#include <random>

// constructors
RPG::RPG(){
    name = "NPC";
    hits_taken = 0;
    luck = 0.1;
    exp = 50.0;
    level = 1;
}

RPG::RPG(string name, int hits_taken, float luck, float exp, int level){
    this->name = name;
    this->hits_taken = hits_taken;
    this->luck = luck;
    this->exp = exp;
    this->level = level;
}

// accessors
string RPG::getName() const{
    return name;
}
int RPG::getHitsTaken() const{
    return hits_taken;
}
float RPG::getLuck() const{
    return luck;
}
float RPG::getExp() const{
    return exp;
}
int RPG::getLevel() const{
    return level;
}

// mutators
/**@brief sets hits_taken to new_hits */
void RPG::setHitsTaken(int new_hits){
    hits_taken = new_hits;
}
/**@brief 
 * returns whether hits_taken is less than MAX_HITS_TAKEN
 * In other words, a player is alive as long as they have not been hit MAX_HITS_TAKEN times
 * 
 * @return true : player is alive
 * @return false : player is unalive
 */
bool RPG::isAlive() const{
    return (MAX_HITS_TAKEN > hits_taken);
}

/**@brief 
 * EXTENDED FUNCTION
 */

void RPG::setName(string name){
    this -> name = name;
}

void RPG::updateExpLevel(){
    exp += 50;
    if (exp >= 100.0){
        level += 1;
        luck += 0.1;
        exp = 0;
    }
}

void RPG::attack(RPG * opponent){
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dis(0.0,1.0);

    float random_num = dis(gen);

    bool hit;

    if (random_num > HIT_FACTOR * opponent->getLuck()){
        opponent->setHitsTaken(opponent->getHitsTaken() + 1);
    }
}

void RPG::printStats(){
    printf("Name: %s\t / Hits Taken: %i\t / Luck: %f\t / EXP: %f\t / Level: %i\t / Status: %d\t",name.c_str(), hits_taken, luck, exp, level, this->isAlive());
}