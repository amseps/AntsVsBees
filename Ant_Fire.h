//
// Created by AM on 10/29/2020.
//

#ifndef ANTSVSBEES_ANT_FIRE_H
#define ANTSVSBEES_ANT_FIRE_H

#include "Ant.h "
#include "AntsVsBees.h"

class Ant_Fire : public Ant{
    ~Ant_Fire();
    Ant_Fire & operator=(Ant_Fire & right);

    void die() override ;

    virtual void attack();
    std::string print() override;

public:
    Ant_Fire();
    Ant_Fire(int pos);

    static const int cost = 4;
};


#endif //ANTSVSBEES_ANT_FIRE_H
