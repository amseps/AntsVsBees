//
// Created by AM on 10/29/2020.
//

#include <iostream>
#include <memory.h>
#include "AntsVsBees.h"

using namespace std;

void AntsVsBees::runGame(){
    BugBoard *b = new BugBoard();
    cout << "\n\n\t\t>>>WELCOME TO ANTS VS BEES<<<"
            "\n\t#You are the glorious red ant army, fighting off disgusting dog bees,"
            "\n\t#place your forces strategically... They are cunning...\n\n";
    while(!runTurn());
    cout << "\n\n#END\n\n";
}

bool AntsVsBees::runTurn() {
    turn++;
    newBee();
    displayStats();
    displayBoard();
    options();
    runActions();
    return isGameOver();
}

void AntsVsBees::displayStats() {
    cout << "-----------------------------------------------------"
    << "\n->Turn: " << turn
    << "\n->Food: " << BugBoard::antFood
    << "\n->[Your move Ants...]"
    << "\n------------------------------------------------------\n";
}

void AntsVsBees::displayBoard() { //sure hope your terminal is monospace
    for(int i = 0 ; i < BugBoard::boardSize; i++){
        cout << "Row " << i << ":\t";
        for(int g = 0; g < BugBoard::bugBoard[i].size(); i++){
            cout << BugBoard::bugBoard[i][g].print() << " ";
        }
        cout << "\n";
    }
}

void AntsVsBees::runActions() {
    for(int i = 0 ; i < BugBoard::boardSize; i++){
        for(int g = 0; g < BugBoard::bugBoard[i].size(); i++){
            BugBoard::bugBoard[i][g].attack();
        }
    }
    for(int i = 0 ; i < BugBoard::boardSize; i++){
        for(int g = 0; g < BugBoard::bugBoard[i].size(); i++){
            BugBoard::bugBoard[i][g].moveForward();
        }
    }
}

void AntsVsBees::options() {
    cout << "TODO: displayStats" << endl;
}

bool AntsVsBees::isGameOver() {
    if(BugBoard::bugBoard[0].size() < 1) return false; // no bugs at all
    for(int i = 0 ; i < BugBoard::bugBoard[0].size(); i++){
        if(! BugBoard::bugBoard[0][i].myID == Bug::bugID::BEE ) return false; // if there's a bug that's not a bee;
    }
    if(BugBoard::bugBoard[0].size() > 0 && BugBoard::bugBoard[0][0].myID == Bug::bugID::BEE){
        return true;
    }
    return false;
}

void AntsVsBees::newBee() {
    Bee * b = new Bee(BugBoard::boardSize-1);
}

AntsVsBees::~AntsVsBees() {

}

AntsVsBees::AntsVsBees() {
    BugBoard();
}

AntsVsBees::AntsVsBees(AntsVsBees &in) {

}


AntsVsBees &AntsVsBees::operator=(AntsVsBees &right) {
    if(this == &right) return *this;
    AntsVsBees * sv = new AntsVsBees(right);
    return *sv;
}

int AntsVsBees::input_getLineInt() {
    string s;
    cout << ">>>";
    getline(cin , s);
    string nums = "";
    for( int i = 0 ; i < s.length(); i++){
        if(isdigit(s[i])) nums += s[i];
    }
    if(nums.length() < 1) return -1;
    int toRet = stoi(nums);
    return toRet;
}




