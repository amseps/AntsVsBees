//
// Created by AM on 10/29/2020.
//

#ifndef ANTSVSBEES_BUG_H
#define ANTSVSBEES_BUG_H

class AntsVsBees;
class BugBoard;

//#include "BugBoard.h"
#include "string"
#include "vector"

class Bug {
public:
    int armor = -1;
    int position = -1;
    int innerpos = -1;
    int foodCost = -1;

    enum bugID{ANT, BEE, BUG, ANT_BODYGUARD, ANT_FIRE, ANT_HARVESTER, ANT_LONGTHROW, ANT_NINJA, ANT_SHORTTHROW, ANT_THROWER, ANT_WALL};
    enum bugID myID;
    Bug();

    virtual std::string print();
    virtual void die();
    virtual void attack(){};
    virtual void takeDamage(int dam);
    virtual void moveForward(){};
};


#endif //ANTSVSBEES_BUG_H
