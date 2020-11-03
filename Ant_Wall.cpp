//
// Created by AM on 10/29/2020.
//

#include "Ant_Wall.h"

Ant_Wall::Ant_Wall() {
    myID = ANT_WALL;
    armor = 4;
}

void Ant_Wall::attack() {
    //doesn't attack
}

std::string Ant_Wall::print() {
    return "[Wall (" + to_string(armor) + "/4)]";
}

Ant_Wall::Ant_Wall(int pos) {
    myID = Bug::bugID::ANT_WALL;
    armor = 4;
    position = pos;
    BugBoard::bugBoard[pos].push_back(this);
    innerpos = BugBoard::bugBoard[pos].size()-1;
}

void Ant_Wall::die() {
    cout << "\n*Wall is slain!*";
    BugBoard::bugBoard[position].erase(BugBoard::bugBoard[position].begin() + innerpos);
    for(int i = 0; i < BugBoard::bugBoard[position].size(); i++) {
        BugBoard::bugBoard[position][i]->innerpos--; //lower the following values if dead individual wasn't the end of the mf list
    }
}
