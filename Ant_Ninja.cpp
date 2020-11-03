//
// Created by AM on 10/29/2020.
//

#include "Ant_Ninja.h"

Ant_Ninja::Ant_Ninja() {
    myID = ANT_NINJA;
    armor = 1;
}

void Ant_Ninja::attack() {
    for(int i = 0 ; i < BugBoard::bugBoard[position].size(); i++){
        if(BugBoard::bugBoard[position][i]->myID == Bug::bugID::BEE){
            cout << "\nSilent ninja strike! ";
            BugBoard::bugBoard[position][i]->takeDamage(1);
        }
    }
}

std::string Ant_Ninja::print() {
    return "[Ninja (" + to_string(armor) + "/1)]";
}

Ant_Ninja::Ant_Ninja(int pos) {
    myID = Bug::bugID::ANT_NINJA;
    armor = 1;
    position = pos;
    BugBoard::bugBoard[pos].push_back(this);
    innerpos = BugBoard::bugBoard[pos].size()-1;
}

void Ant_Ninja::die() {
    cout << "\n*Ninja is slain! What?*\n";
    BugBoard::bugBoard[position].erase(BugBoard::bugBoard[position].begin() + innerpos);
    for(int i = 0; i < BugBoard::bugBoard[position].size(); i++) {
        BugBoard::bugBoard[position][i]->innerpos--; //lower the following values if dead individual wasn't the end of the mf list
    }
}
