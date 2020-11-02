//
// Created by AM on 10/29/2020.
//

#ifndef ANTSVSBEES_ANT_THROWER_H
#define ANTSVSBEES_ANT_THROWER_H


#include "Ant.h "

class Ant_Thrower : public Ant{
    Ant_Thrower();
    ~Ant_Thrower();
    Ant_Thrower & operator=(Ant_Thrower & right);

    void attack();
};


#endif //ANTSVSBEES_ANT_THROWER_H
