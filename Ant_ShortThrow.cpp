//
// Created by AM on 10/29/2020.
//

#include "Ant_ShortThrow.h"

Ant_ShortThrow::Ant_ShortThrow() {
    myID = ANT_SHORTTHROW;
    armor = 1;
}

void Ant_ShortThrow::attack() {
    int from, to;
    from = position -2;
    to = position +2;
    if(from < 0) from = 0;
    if(to > BugBoard::boardSize) to = BugBoard::boardSize;
    for(int i = from; i <= to; i++){
        for(int g = 0 ; g < BugBoard::bugBoard[i].size(); g++){
            if(BugBoard::bugBoard[i][g].myID == Bug::bugID::BEE) BugBoard::bugBoard[i][g].takeDamage(1);
        }
    }
}

std::string Ant_ShortThrow::print() {
    return "[Shortthrower " + to_string(armor) + "/1)]";
}
