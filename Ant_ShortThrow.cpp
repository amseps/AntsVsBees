//
// Created by AM on 10/29/2020.
//

#include "Ant_ShortThrow.h"

Ant_ShortThrow::Ant_ShortThrow() {
    myID = ANT_SHORTTHROW;
    armor = 1;
}

void Ant_ShortThrow::attack() {
    cout << "Shortthrower attacks! 1 damage!\n";
    int from, to;
    from = position -2;
    to = position +2;
    if(from < 0) from = 0;
    if(to > BugBoard::boardSize) to = BugBoard::boardSize;
    bool hitOne = false;
    for(int i = from; i <= to; i++){
        for(int g = 0 ; g < BugBoard::bugBoard[i].size(); g++){
            if(BugBoard::bugBoard[i][g]->myID == Bug::bugID::BEE){
                BugBoard::bugBoard[i][g]->takeDamage(1);
                hitOne = true;
                break;
            }
        }
        if(hitOne) break;
    }
}

std::string Ant_ShortThrow::print() {
    return "[Shortthrower " + to_string(armor) + "/1)]";
}

Ant_ShortThrow::Ant_ShortThrow(int pos) {
    myID = Bug::bugID::ANT_SHORTTHROW;
    armor = 1;
    position = pos;
    BugBoard::bugBoard[pos].push_back(this);
    innerpos = BugBoard::bugBoard[pos].size()-1;
}

void Ant_ShortThrow::die() {
    cout << "\n*Shortthrower is slain!*\n";
    BugBoard::bugBoard[position].erase(BugBoard::bugBoard[position].begin() + innerpos);
    for(int i = 0; i < BugBoard::bugBoard[position].size(); i++) {
        BugBoard::bugBoard[position][i]->innerpos--; //lower the following values if dead individual wasn't the end of the mf list
    }
}
