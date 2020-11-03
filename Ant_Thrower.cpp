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

Ant_Thrower::Ant_Thrower(int pos) {
    myID = Bug::bugID::ANT_THROWER; //I feel that I should be implementing the second half of these in the super BUG class
    armor = 1;
    position = pos;
    BugBoard::bugBoard[pos].push_back(this);
    innerpos = BugBoard::bugBoard[pos].size()-1;
}

void Ant_Thrower::die() {
    cout << "\n*Thrower is slain!*\n";
    BugBoard::bugBoard[position].erase(BugBoard::bugBoard[position].begin() + innerpos);
    for(int i = 0; i < BugBoard::bugBoard[position].size(); i++) {
        BugBoard::bugBoard[position][i]->innerpos--; //lower the following values if dead individual wasn't the end of the mf list
    }
}
