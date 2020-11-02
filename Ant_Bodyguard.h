//
// Created by AM on 10/29/2020.
//

#ifndef ANTSVSBEES_ANT_BODYGUARD_H
#define ANTSVSBEES_ANT_BODYGUARD_H

class BugBoard;
#include "BugBoard.h"

#include "Ant.h"

class Ant_Bodyguard : public Ant{
    Ant_Bodyguard();
    ~Ant_Bodyguard();
    Ant_Bodyguard & operator=(Ant_Bodyguard & right);

    void attack();
};


#endif //ANTSVSBEES_ANT_BODYGUARD_H
