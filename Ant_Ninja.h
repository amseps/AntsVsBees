//
// Created by AM on 10/29/2020.
//

#ifndef ANTSVSBEES_ANT_NINJA_H
#define ANTSVSBEES_ANT_NINJA_H

#include "Ant.h"

class Ant_Ninja : public Ant{
    Ant_Ninja();
    ~Ant_Ninja();
    Ant_Ninja & operator=(Ant_Ninja & right);

    void attack();
};


#endif //ANTSVSBEES_ANT_NINJA_H
