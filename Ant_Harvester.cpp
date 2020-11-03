//
// Created by AM on 10/29/2020.
//

#include "Ant_Harvester.h"

void Ant_Harvester::attack() {
    BugBoard::antFood += 1;
    cout << "\nHarvester produces one food...";
}

Ant_Harvester::Ant_Harvester() {
    myID = Bug::bugID::ANT_HARVESTER;
    armor = 1;
}

std::string Ant_Harvester::print() {
    return "[Harvester (" + to_string(armor) + "/1)]";
}

Ant_Harvester::Ant_Harvester(int pos) {
    myID = Bug::bugID::ANT_HARVESTER;
    armor = 1;
    position = pos;
    BugBoard::bugBoard[pos].push_back(this);
    innerpos = BugBoard::bugBoard[pos].size()-1;
}

void Ant_Harvester::die() {
    cout << "\n*Harvester is slain!*\n";
    BugBoard::bugBoard[position].erase(BugBoard::bugBoard[position].begin() + innerpos);
    for(int i = 0; i < BugBoard::bugBoard[position].size(); i++) {
        BugBoard::bugBoard[position][i]->innerpos--; //lower the following values if dead individual wasn't the end of the mf list
    }
}
