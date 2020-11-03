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
        if(BugBoard::bugBoard[position][i].myID == Bug::bugID::BEE){
            BugBoard::bugBoard[position][i].takeDamage(1);
        }
    }
}

std::string Ant_Ninja::print() {
    return "[Ninja (" + to_string(armor) + "/1)]";
}
