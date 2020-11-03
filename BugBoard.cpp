//
// Created by AM on 11/2/2020.
//


#include "BugBoard.h"

int BugBoard::antFood = 50;///// ???????? ok? ? ?
vector<vector<Bug*>> BugBoard::bugBoard = *new vector<vector<Bug*>>;

BugBoard::BugBoard() {
    BugBoard::bugBoard.resize(boardSize);
    for(int i = 0 ; i < bugBoard.size(); i++){
        bugBoard[i] = *new vector<Bug*>(0);
    }
    BugBoard::antFood = 50;
}

Bug* BugBoard::isBodyguardHere(int index) {
    for(int i = 0 ; i < bugBoard[index].size(); i++){
        if(bugBoard[index][i]->myID == Bug::bugID::ANT_BODYGUARD) return bugBoard[index][i];
    }
    return nullptr;
}

Bug* BugBoard::isBeeHere(int index) {
    for(int i = 0 ; i < bugBoard[index].size(); i++){
        if(bugBoard[index][i]->myID == Bug::bugID::BEE) return bugBoard[index][i];
    }
    return nullptr;
}

Bug* BugBoard::isAntHere(int index) {
    for(int i = 0 ; i < bugBoard[index].size(); i++){
        if(bugBoard[index][i]->myID != Bug::bugID::BEE) return bugBoard[index][i]; //lazy!
    }
    return nullptr;
}

void BugBoard::listItems() {
    for(int i = 0 ; i < bugBoard.size(); i++){
        for(int g = 0 ; g < bugBoard[i].size() ; g++){
            cout << bugBoard[i][g]->myID << " ";
        }
    }
}
