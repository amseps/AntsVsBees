//
// Created by AM on 10/29/2020.
//

#include "Ant_LongThrow.h"
#include "BugBoard.h"

void Ant_LongThrow::attack() {
    int after, before;
    after = position + 4;
    before = position -4;
    for(int i = after; i < BugBoard::boardSize; i++){
        for(int g = 0 ; g < BugBoard::bugBoard[i].size(); g++){
            if(BugBoard::bugBoard[i][g].myID == Bug::bugID::BEE) BugBoard::bugBoard[i][g].takeDamage(1);
        }
    }
    for(int i = 0; i <= before; i++){
        for(int g = 0 ; g < BugBoard::bugBoard[i].size(); g++){
            if(BugBoard::bugBoard[i][g].myID == Bug::bugID::BEE) BugBoard::bugBoard[i][g].takeDamage(1);
        }
    }
}

Ant_LongThrow::Ant_LongThrow() {
    armor = 1;
    myID = Bug::bugID::ANT_LONGTHROW;
}

std::string Ant_LongThrow::print() {
    return "[Longthrower " + to_string(armor) + "/1)]";
}
