//
// Created by AM on 10/29/2020.
//

#ifndef ANTSVSBEES_BEE_H
#define ANTSVSBEES_BEE_H

class BugBoard;
class Bee;

#include "Bug.h"
#include "BugBoard.h"

class Bee : public Bug{
public:

    Bee();
    Bee(int position);
    void die() override;
    void attack() override;
    void moveForward() override;


    std::string print() override;
};


#endif //ANTSVSBEES_BEE_H
