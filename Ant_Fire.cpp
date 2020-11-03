//
// Created by AM on 10/29/2020.
//

#include "Ant_Fire.h"

Ant_Fire::Ant_Fire() {
    myID = ANT_FIRE;
    armor = 1;
}

void Ant_Fire::attack() {
    ;//do nothing only attack on deathe
}

std::string Ant_Fire::print() {
    return "[Fire (" + to_string(armor) + "/1)]";
}
