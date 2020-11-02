//
// Created by AM on 10/29/2020.
//

#ifndef ANTSVSBEES_ANT_WALL_H
#define ANTSVSBEES_ANT_WALL_H


#include "Ant.h"

class Ant_Wall : public Ant{
    Ant_Wall();
    ~Ant_Wall();
    Ant_Wall & operator=(Ant_Wall & right);

    void attack();
};


#endif //ANTSVSBEES_ANT_WALL_H
