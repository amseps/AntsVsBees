//
// Created by AM on 10/29/2020.
//

#ifndef ANTSVSBEES_ANT_NINJA_H
#define ANTSVSBEES_ANT_NINJA_H

#include "Ant.h"
#include "BugBoard.h"

class Ant_Ninja : public Ant{
    ~Ant_Ninja();
    Ant_Ninja & operator=(Ant_Ninja & right);

    void die() override ;
    void attack();

    std::string print() override;
public:
    Ant_Ninja();
    Ant_Ninja(int pos);
    static const int cost = 6;
};


#endif //ANTSVSBEES_ANT_NINJA_H
