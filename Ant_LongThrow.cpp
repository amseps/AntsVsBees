//
// Created by AM on 10/29/2020.
//

#include "Ant_LongThrow.h"
#include "BugBoard.h"

void Ant_LongThrow::attack() {
    cout << "\nLongthrower attacks! One damage";
    int after, before;
    after = position + 4;
    before = position -4;
    bool hitOne = false;
    for(int i = after; i < BugBoard::boardSize; i++){
        for(int g = 0 ; g < BugBoard::bugBoard[i].size(); g++){
            if(BugBoard::bugBoard[i][g]->myID == Bug::bugID::BEE) {
                BugBoard::bugBoard[i][g]->takeDamage(1);
                hitOne = true;
                break;
            }
        }
        if(hitOne) break;
    }
    hitOne = false;
    for(int i = 0; i <= before; i++){
        for(int g = 0 ; g < BugBoard::bugBoard[i].size(); g++){
            if(BugBoard::bugBoard[i][g]->myID == Bug::bugID::BEE){
                BugBoard::bugBoard[i][g]->takeDamage(1);
                hitOne = true;
                break;
            }
        }
        if(hitOne)break;
    }
}

Ant_LongThrow::Ant_LongThrow() {
    armor = 1;
    myID = Bug::bugID::ANT_LONGTHROW;
}

std::string Ant_LongThrow::print() {
    return "[Longthrower " + to_string(armor) + "/1)]";
}

Ant_LongThrow::Ant_LongThrow(int pos) {
    myID = Bug::bugID::ANT_LONGTHROW;
    armor = 1;
    position = pos;
    BugBoard::bugBoard[pos].push_back(this);
    innerpos = BugBoard::bugBoard[pos].size()-1;
}

void Ant_LongThrow::die() {
    cout << "\n*Longthrower is slain!*\n";
    BugBoard::bugBoard[position].erase(BugBoard::bugBoard[position].begin() + innerpos);
    for(int i = 0; i < BugBoard::bugBoard[position].size(); i++) {
        BugBoard::bugBoard[position][i]->innerpos--; //lower the following values if dead individual wasn't the end of the mf list
    }
}
