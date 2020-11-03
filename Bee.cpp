//
// Created by AM on 10/29/2020.
//

#include "Bee.h"


Bee::Bee() {
    myID = Bug::bugID::BEE;
    armor = 3;
    position = -1;
    innerpos = -1;
}

Bee::Bee(int pos){
    myID = Bug::bugID::BEE;
    armor = 3;
    position = pos;
    BugBoard::bugBoard[pos].push_back(*this);
    innerpos = BugBoard::bugBoard[pos].size()-1;
}



void Bee::attack() {
    for(int i = 0; i < BugBoard::bugBoard[position].size(); i++){
        if(BugBoard::bugBoard[position][i].myID != Bug::bugID::BEE && BugBoard::bugBoard[position][i].myID == Bug::bugID::ANT_BODYGUARD){// if it's not a bee and is a bodyguard
            BugBoard::bugBoard[position][i].takeDamage(1);
            return;
        }
    }
    for(int i = 0; i < BugBoard::bugBoard[position].size(); i++){
        if(BugBoard::bugBoard[position][i].myID != Bug::bugID::BEE){// if it's not a bee and is a bodyguard
            BugBoard::bugBoard[position][i].takeDamage(1);
            return;
        }
    }
}

void Bee::moveForward() {
    if(position == 0) return;
    for(int i = 0; i < BugBoard::bugBoard[position].size(); i++){
        if(BugBoard::bugBoard[position][i].myID != Bug::bugID::BEE && BugBoard::bugBoard[position][i].myID != Bug::bugID::ANT_NINJA){// if it's not a bee and is not a ninja
            return; //then can't move forward
        }
    }
    BugBoard::bugBoard[position-1].push_back(*this);
    position -= 1;
    innerpos = BugBoard::bugBoard[position].size()-1;
    delete &BugBoard::bugBoard[position][innerpos];
}

void Bee::die() {
    BugBoard::bugBoard[position].erase(BugBoard::bugBoard[position].begin() + innerpos);
}

std::string Bee::print() {
    return "[BEE (" + to_string(armor) + "/3)]";
}
