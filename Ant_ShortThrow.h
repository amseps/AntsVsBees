//
// Created by AM on 10/29/2020.
//

#ifndef ANTSVSBEES_ANT_SHORTTHROW_H
#define ANTSVSBEES_ANT_SHORTTHROW_H


#include "Ant.h"
#include "BugBoard.h"

class Ant_ShortThrow : public Ant{
    Ant_ShortThrow();
    ~Ant_ShortThrow();
    Ant_ShortThrow & operator=(Ant_ShortThrow & right);

    void attack();

    std::string print() override;
};

#endif //ANTSVSBEES_ANT_SHORTTHROW_H
