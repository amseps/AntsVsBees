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
    newBee();
    displayStats();
    displayBoard();
    //BugBoard::listItems();
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
    for(int i = 0 ; i < BugBoard::bugBoard.size(); i++){
        cout << "Row " << i << ":\t";
        vector<Bug*> a = BugBoard::bugBoard[i];
        for(int g = 0; g < a.size(); g++){
            cout << a[g]->print() << " ";
        }
        cout << "\n";
    }
}

void AntsVsBees::runActions() {
    for(int i = 0 ; i < BugBoard::boardSize; i++){
        vector<Bug*> a = BugBoard::bugBoard[i];
        for(int g = 0; g < a.size(); g++){
            a[g]->attack();
        }
    }
    for(int i = 0 ; i < BugBoard::boardSize; i++){
        vector<Bug*> a = BugBoard::bugBoard[i];
        for(int g = 0; g < a.size(); g++){
            a[g]->moveForward();
        }
    }
}

void AntsVsBees::options() {
    cout << "\nWhat will you do commander?"
            "\n[0:Nothing! ; 1:Harvester ; 2: FireAnt ; 3: LongThrower ; 4: ShortThrower ; 5: Thrower ; 6:Bodyguard : 7: Ninja ; 8: Wall]";
    string s;
    cout << "\n>>>";
    cin >> s;
}

bool AntsVsBees::isGameOver() {
    if(BugBoard::bugBoard[0].size() < 1) return false; // no bugs at all
    for(int i = 0 ; i < BugBoard::bugBoard[0].size(); i++){
        if(! BugBoard::bugBoard[0][i]->myID == Bug::bugID::BEE ) return false; // if there's a bug that's not a bee;
    }
    if(BugBoard::bugBoard[0].size() > 0 && BugBoard::bugBoard[0][0]->myID == Bug::bugID::BEE){
        cout << "\n************************************************************"
                "\n### NOOO!!! NOT THE BEES!! Your colony has been destroyed! ###"
                "\n************************************************************";
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




