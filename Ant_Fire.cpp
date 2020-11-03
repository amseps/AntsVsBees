//
// Created by AM on 10/29/2020.
//

#include "Ant_Fire.h"

Ant_Fire::Ant_Fire() {
    myID = ANT_FIRE;
    armor = 1;
}

void Ant_Fire::attack() {
    ;//do nothing only attack on deathe
}

std::string Ant_Fire::print() {
    return "[Fire (" + to_string(armor) + "/1)]";
}

Ant_Fire::Ant_Fire(int pos) {
    myID = Bug::bugID::ANT_FIRE;
    armor = 1;
    position = pos;
    BugBoard::bugBoard[pos].push_back(this);
    innerpos = BugBoard::bugBoard[pos].size()-1;
}

void Ant_Fire::die(){
    cout << "\n<<Fire Ant Explodes!>>";
    for(int i = 0 ; i < BugBoard::bugBoard[position].size(); i++){
        if(BugBoard::bugBoard[position][i]->myID == Bug::bugID::BEE){
            BugBoard::bugBoard[position][i]->takeDamage(10);
        }
    }
    vector<Bug*> b = BugBoard::bugBoard[position];
    BugBoard::bugBoard[position].erase(BugBoard::bugBoard[position].begin() + innerpos);
    for(int i = 0; i < BugBoard::bugBoard[position].size(); i++) {
        BugBoard::bugBoard[position][i]->innerpos--; //lower the following values if dead individual wasn't the end of the mf list
    }
}