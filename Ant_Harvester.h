//
// Created by AM on 10/29/2020.
//

#ifndef ANTSVSBEES_ANT_HARVESTER_H
#define ANTSVSBEES_ANT_HARVESTER_H

#include "Ant.h "
#include "BugBoard.h"

class Ant_Harvester : public Ant{

    ~Ant_Harvester();
    Ant_Harvester & operator=(Ant_Harvester & right);

    void die() override ;

    void attack();
    std::string print() override;

public:
    Ant_Harvester();
    Ant_Harvester(int pos);
    static const int cost = 2;
};


#endif //ANTSVSBEES_ANT_HARVESTER_H
