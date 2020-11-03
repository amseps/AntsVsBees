//
// Created by AM on 11/2/2020.
//

#ifndef ANTSVSBEES_BUGBOARD_H
#define ANTSVSBEES_BUGBOARD_H

using namespace std;

//blessed be my circular logic
class BugBoard;
class Ant_Fire; // what a fool I am
class Ant_LongThrow;
class Ant_ShortThrow;
class Ant_Bodyguard;
class Ant_Harvester;
class Ant_Ninja;
class Ant_Thrower;
class Ant_Wall;
class Ant_Wall;
class Ant;
class Bee;
//class AntsVsBees;

#include "Ant.h"
#include "Ant_Fire.h"
#include "Ant_LongThrow.h"
#include "Ant_ShortThrow.h"
#include "Ant_Bodyguard.h"
#include "Ant_Harvester.h"
#include "Ant_Ninja.h"
#include "Ant_Thrower.h"
#include "Ant_Wall.h"
#include "Bee.h"
//#include "AntsVsBees.h"

#include "vector"

class BugBoard {
public:
    static const int boardSize = 10;
    static vector<vector<Bug>> bugBoard;
    static int antFood;
    Bug* isBodyguardHere(int index);
    Bug* isBeeHere(int index);
    Bug* isAntHere(int index);

    BugBoard();
    //static only class
};


#endif //ANTSVSBEES_BUGBOARD_H
