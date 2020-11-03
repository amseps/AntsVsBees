//
// Created by AM on 10/29/2020.
//

#include "Ant_Thrower.h"

Ant_Thrower::Ant_Thrower() {
    myID = ANT_THROWER;
    armor = 1;
}

void Ant_Thrower::attack(){
    for(int i = 0 ; i < BugBoard::bugBoard[position].size(); i++){
        if(BugBoard::bugBoard[position][i]->myID == Bug::bugID::BEE){
            BugBoard::bugBoard[position][i];
            break;
        }
    }
}

std::string Ant_Thrower::print() {
    return "[Thrower (" + to_string(armor) +"/1)]";
}
