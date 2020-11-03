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

Ant_Bodyguard::Ant_Bodyguard(int pos) {
    myID = Bug::bugID::ANT_BODYGUARD;
    armor = 2;
    position = pos;
    BugBoard::bugBoard[pos].push_back(this);
    innerpos = BugBoard::bugBoard[pos].size()-1;
}

void Ant_Bodyguard::die() {
    cout << "\n*Bodyguard is slain!*\n";
    BugBoard::bugBoard[position].erase(BugBoard::bugBoard[position].begin() + innerpos);
    for(int i = 0; i < BugBoard::bugBoard[position].size(); i++) {
        BugBoard::bugBoard[position][i]->innerpos--; //lower the following values if dead individual wasn't the end of the mf list
    }
}
