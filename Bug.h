//
// Created by AM on 10/29/2020.
//

#ifndef ANTSVSBEES_BUG_H
#define ANTSVSBEES_BUG_H

class AntsVsBees;

#include "string"
#include "vector"

class Bug {
public:
    enum bugID{ANT, BEE, BUG, ANT_BODYGUARD, ANT_FIRE, ANT_HARVESTER, ANT_LONGTHROW, ANT_NINJA, ANT_SHORTTHROW, ANT_THROWER, ANT_WALL};
    enum bugID myID;
    Bug();
};


#endif //ANTSVSBEES_BUG_H
