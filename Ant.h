//
// Created by AM on 10/29/2020.
//

#ifndef ANTSVSBEES_ANT_H
#define ANTSVSBEES_ANT_H

class BugBoard;
class Ant;

#include "Bug.h"
//#include "BugBoard.h"

class Ant : public Bug {

public:

    void die() override;
    void attack() override{};
    void moveForward() override{};

    int foodCost = -1;


    Ant();
    ~Ant();
    Ant & operator=(Ant & right);
};


#endif //ANTSVSBEES_ANT_H
