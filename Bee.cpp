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
    BugBoard::bugBoard[pos].push_back(this);
    innerpos = BugBoard::bugBoard[pos].size()-1;
}



void Bee::attack() {
    vector<Bug*> a = BugBoard::bugBoard[position];
    for(int i = 0; i < a.size(); i++){
        if(a[i]->myID == Bug::bugID::ANT_BODYGUARD){// if it is a bodyguard
            a[i]->takeDamage(1);
            return;
        }
    }
    for(int i = 0; i < a.size(); i++){
        if(a[i]->myID != Bug::bugID::BEE && a[i]->myID != Bug::bugID::ANT_NINJA){// if it's not a bee and is not a ninja ->> and is not a bodyguard
            a[i]->takeDamage(1);
            return;
        }
    }
}

void Bee::moveForward() {
    if(position == 0) return;
    for(int i = 0; i < BugBoard::bugBoard[position].size(); i++){
        if(BugBoard::bugBoard[position][i]->myID != Bug::bugID::BEE && BugBoard::bugBoard[position][i]->myID != Bug::bugID::ANT_NINJA){// if it's not a bee and is not a ninja
            return; //then can't move forward
        }
    }
    BugBoard::bugBoard[position-1].push_back(this);
    swap(BugBoard::bugBoard[position][innerpos], BugBoard::bugBoard[position][BugBoard::bugBoard[position].size()-1]); // swap this element with last element
    BugBoard::bugBoard[position][innerpos]->innerpos = position-1; // the last elements innerpos is now equal to my old position
    BugBoard::bugBoard[position].resize(BugBoard::bugBoard[position].size()-1); //then shrink by one
    position -= 1; // update to new position
    innerpos = BugBoard::bugBoard[position].size()-1; // it's on the end of the next vector
}

void Bee::die() {
    cout << "*Bee is slain!*\n";
    vector<Bug*> b = BugBoard::bugBoard[position];
    BugBoard::bugBoard[position].erase(BugBoard::bugBoard[position].begin() + innerpos);
    for(int i = 0; i < BugBoard::bugBoard[position].size(); i++) {
        BugBoard::bugBoard[position][i]->innerpos--; //lower the following values if dead individual wasn't the end of the mf list
    }
}

std::string Bee::print() {
    return "[BEE (" + to_string(armor) + "/3)]";
}
