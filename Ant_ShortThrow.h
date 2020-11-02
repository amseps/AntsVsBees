//
// Created by AM on 10/29/2020.
//

#ifndef ANTSVSBEES_ANT_SHORTTHROW_H
#define ANTSVSBEES_ANT_SHORTTHROW_H


#include "Ant.h"

class Ant_ShortThrow : public Ant{
    Ant_ShortThrow();
    ~Ant_ShortThrow();
    Ant_ShortThrow & operator=(Ant_ShortThrow & right);

    void attack();
};

#endif //ANTSVSBEES_ANT_SHORTTHROW_H
