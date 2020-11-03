//
// Created by AM on 10/29/2020.
//

#include "Ant_Wall.h"

Ant_Wall::Ant_Wall() {
    myID = ANT_WALL;
    armor = 4;
}

void Ant_Wall::attack() {
    //doesn't attack
}

std::string Ant_Wall::print() {
    return "[Wall (" + to_string(armor) + "/4)]";
}
