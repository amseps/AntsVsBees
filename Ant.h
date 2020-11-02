//
// Created by AM on 10/29/2020.
//

#ifndef ANTSVSBEES_ANT_H
#define ANTSVSBEES_ANT_H


#include "Bug.h"

class Ant : public Bug {

public:

    void takeDamage();
    virtual void attack();

    int position = 0;
    int foodCost = 1;
    int armor = 1;


    Ant();
    ~Ant();
    Ant & operator=(Ant & right);
};


#endif //ANTSVSBEES_ANT_H
