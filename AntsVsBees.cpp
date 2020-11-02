//
// Created by AM on 10/29/2020.
//

#include <iostream>
#include <memory.h>
#include "AntsVsBees.h"

using namespace std;

void AntsVsBees::runGame(){
    cout << "\n\n\t\t>>>WELCOME TO ANTS VS BEES<<<"
            "\n\t#You are the glorious red ant army, fighting off disgusting dog bees,"
            "\n\t#place your forces strategically... They are cunning...\n\n";
    while(!runTurn());
    cout << "\n\n#END\n\n";
}

bool AntsVsBees::runTurn() {
    turn++;
    displayStats();
    displayBoard();
    options();
    runActions();
    return isGameOver();
}

void AntsVsBees::displayStats() {
    cout << "TODO: displayStats" << endl;
}

void AntsVsBees::displayBoard() { //sure hope your terminal is monospace
    cout << "TODO: displayStats" << endl;
}

void AntsVsBees::runActions() {
    cout << "TODO: displayStats" << endl;
}

void AntsVsBees::options() {
    cout << "TODO: displayStats" << endl;
}

bool AntsVsBees::isGameOver() {
    return false;
}

AntsVsBees::~AntsVsBees() {

}

AntsVsBees::AntsVsBees() {

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


