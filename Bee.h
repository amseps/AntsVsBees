//
// Created by AM on 10/29/2020.
//

#ifndef ANTSVSBEES_BEE_H
#define ANTSVSBEES_BEE_H

#include "Bug.h"

class Bee : public Bug{
public:

    Bee();

    int armor = 3;
    int position = 9;

    void attack();
    void moveForward();
};


#endif //ANTSVSBEES_BEE_H
