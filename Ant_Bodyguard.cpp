//
// Created by AM on 10/29/2020.
//

#include "Ant_Bodyguard.h"

void Ant_Bodyguard::attack() {

}

Ant_Bodyguard::Ant_Bodyguard() {
    myID = ANT_BODYGUARD;
    armor = 2;
}

std::string Ant_Bodyguard::print() {
    return "[Bodyguard (" + to_string(armor) + "/2)]";
}
