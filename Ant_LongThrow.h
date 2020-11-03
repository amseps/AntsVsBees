//
// Created by AM on 10/29/2020.
//

#ifndef ANTSVSBEES_ANT_LONGTHROW_H
#define ANTSVSBEES_ANT_LONGTHROW_H

#include "Ant.h"
#include "BugBoard.h"

class Ant_LongThrow : public Ant{
    ~Ant_LongThrow();
    Ant_LongThrow & operator=(Ant_LongThrow & right);

    void die() override ;
    void attack();

    std::string print() override;

public:
    Ant_LongThrow();
    Ant_LongThrow(int pos);
    static const int cost = 3;
};


#endif //ANTSVSBEES_ANT_LONGTHROW_H
