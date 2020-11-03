//
// Created by AM on 10/29/2020.
//

#include "Ant_Harvester.h"

void Ant_Harvester::attack() {
    myID = Bug::bugID::ANT_HARVESTER;
    armor = 1;
}

Ant_Harvester::Ant_Harvester() {
    BugBoard::antFood += 1;
}

std::string Ant_Harvester::print() {
    return "[Harvester (" + to_string(armor) + "/1)]";
}
