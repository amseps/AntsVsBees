//
// Created by AM on 10/29/2020.
//

#ifndef ANTSVSBEES_ANT_HARVESTER_H
#define ANTSVSBEES_ANT_HARVESTER_H

#include "Ant.h "
#include "BugBoard.h"

class Ant_Harvester : public Ant{
    Ant_Harvester();
    ~Ant_Harvester();
    Ant_Harvester & operator=(Ant_Harvester & right);

    void attack();
    std::string print() override;
};


#endif //ANTSVSBEES_ANT_HARVESTER_H
