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
            "\n\t#place your forces strategically... They are cunning...\n\n"
            "\n\tHarvester cost:2 armor:1      - An ant that gives the colony 1 food each turn, food is used to produce more ants"
            "\n\tThrower: cost:4 armor:1       - A basic ant that will attack a single Bee on its own square"
            "\n\tFire Ant: cost:4 armor:1      - A radical ant that will detonate on death, and cause 10 damage to all Bees on its square!"
            "\n\tLong Thrower: cost:3 armor:1  - A radical ant that will throw once behind and once ahead, doing damage to one enemy on each side that is at least 4 squares away"
            "\n\tShort Thrower: cost:3 armor:1 - Just like the long thrower, except hits targets within 2 squares of space"
            "\n\tWall Ant: cost:4 armor:4      - An ant that does no damage to Bees, but provides a strong defence!"
            "\n\tNinja Ant: cost:6 armor:1     - A mysterious wanderer that can't be hit by Bees, and does one damage to each that passes!"
            "\n\tBodyguard Ant: cost:4 armor:2 - This fellow lays down his life! He does no damage, but can be placed on a square held by other ants to protect them!\n\n";
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
    cout << "\n-----------------------------------------------------"
    << "\n\t->Turn: " << turn
    << "\n\t->Food: " << BugBoard::antFood
    << "\n\t->[Your move Ants...]"
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
    cout << "\n\n################################\n";
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
    cout << "\n################################\n";
}

void AntsVsBees::options() {
    cout << "\n\t>What will you do commander?"
            "\n\t>[0:Nothing! ; 1:Harvester ; 2: FireAnt ; 3: LongThrower ;"
            "\n\t>4: ShortThrower ; 5: Thrower ; 6:Bodyguard : 7: Ninja ; 8: Wall]\n";
    switch(int a = input_getLineInt()){
        case 0: default:
            break;
        case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: //hmm
            while(true) {
                cout << "\nPlaced on which row of the board? Position: \n";
                int b = input_getLineInt();
                Bug *c = BugBoard::isAntHere(b);
                if (c != nullptr && c->myID != Bug::ANT_BODYGUARD && a != 6) { // order matters  ; a != 6 means placing a bodyguard, also the other is if bodyguard already there can place :)
                    cout << "There's already an ant here!\nType somewhere else";
                }else if(b < 0 || b > BugBoard::boardSize){
                    break;
                }else{
                    bool tooExpensive = false;
                    switch(a){ // fool ;  this is all stupid actually vvvv put it in the class????
                                case 1: if(Ant_Harvester::cost < BugBoard::antFood){ BugBoard::antFood -= Ant_Harvester::cost; makeANewBugOfTypeAt(Bug::bugID::ANT_HARVESTER, b); break;}else{tooExpensive = true; break;}
                        case 2: if(Ant_Fire::cost < BugBoard::antFood){ BugBoard::antFood -= Ant_Fire::cost;makeANewBugOfTypeAt(Bug::bugID::ANT_FIRE, b); break;}else{tooExpensive = true; break;}
                        case 3: if(Ant_LongThrow::cost < BugBoard::antFood){ BugBoard::antFood -= Ant_LongThrow::cost;makeANewBugOfTypeAt(Bug::bugID::ANT_LONGTHROW, b); break;}else{tooExpensive = true; break;}
                        case 4: if(Ant_ShortThrow::cost < BugBoard::antFood){ BugBoard::antFood -= Ant_ShortThrow::cost;makeANewBugOfTypeAt(Bug::bugID::ANT_SHORTTHROW, b); break;}else{tooExpensive = true; break;}
                        case 5: if(Ant_Thrower::cost < BugBoard::antFood){ BugBoard::antFood -= Ant_Thrower::cost;makeANewBugOfTypeAt(Bug::bugID::ANT_THROWER, b); break;}else{tooExpensive = true; break;}
                        case 6:
                            if(c != nullptr && c->myID == Bug::ANT_BODYGUARD){ //if placing two bodyguards!
                                cout << "\nCan't put two bodyguards on one spot!\n";
                                break;
                            }
                            else if(Ant_Bodyguard::cost < BugBoard::antFood){
                                BugBoard::antFood -= Ant_Bodyguard::cost;
                                makeANewBugOfTypeAt(Bug::bugID::ANT_BODYGUARD, b);
                                break;
                            }else{
                                tooExpensive = true;
                                break;
                            }
                        case 7: if(Ant_Ninja::cost < BugBoard::antFood){ BugBoard::antFood -= Ant_Ninja::cost;makeANewBugOfTypeAt(Bug::bugID::ANT_NINJA, b); break;}else{tooExpensive = true; break;}
                        case 8: if(Ant_Wall::cost < BugBoard::antFood){ BugBoard::antFood -= Ant_Wall::cost;makeANewBugOfTypeAt(Bug::bugID::ANT_WALL, b); break;}else{tooExpensive = true; break;}
                        default: break;
                    }
                    if(tooExpensive) cout << "\n!That bug costs too much!\n";
                    break; //escape while
                }
            }
            break;
    }
}

void AntsVsBees::makeANewBugOfTypeAt(Bug::bugID bugType, int pos) {
    switch(bugType){
        case Bug::bugID::ANT_HARVESTER:
            new Ant_Harvester(pos);
            break;
        case Bug::bugID::ANT_FIRE:
            new Ant_Fire(pos);
            break;
        case Bug::bugID::ANT_LONGTHROW:
            new Ant_LongThrow(pos);
            break;
        case Bug::bugID::ANT_SHORTTHROW:
            new Ant_ShortThrow(pos);
            break;
        case Bug::bugID::ANT_THROWER:
            new Ant_Thrower(pos);
            break;
        case Bug::bugID::ANT_BODYGUARD:
            new Ant_Bodyguard(pos);
            break;
        case Bug::bugID::ANT_NINJA:
            new Ant_Ninja(pos);
            break;
        case Bug::bugID::ANT_WALL:
            new Ant_Wall(pos);
            break;
        case Bug::bugID::ANT:
            cout << "[TODO:Gen-Ant]";
            break;
        case Bug::bugID::BEE:
            new Bee(pos);
            break;
        default: break;
    }
}

bool AntsVsBees::isGameOver() {
    for(int i = 0 ; i < BugBoard::bugBoard[0].size(); i++){
        if(! BugBoard::bugBoard[0][i]->myID == Bug::bugID::BEE ) return false; // if there's a bug that's not a bee;
    }// so there's no bugs on square 0
    if(BugBoard::bugBoard[0].size() > 0 && BugBoard::bugBoard[0][0]->myID == Bug::bugID::BEE){
        cout << "\n************************************************************"
                "\n### NOOO!!! NOT THE BEES!! Your colony has been destroyed! ###"
                "\n************************************************************";
        return true;
    }
    bool isBees = false;
    for(int i = 0 ; i < BugBoard::boardSize; i++){ //check if there are any bees at all
        if(BugBoard::isBeeHere(i) != nullptr){
            isBees = true;
            break;
        }
    }
    if(!isBees){//if there is no bees at all
        cout << "\n************************************************************"
                "\n### Woah! All of the bees have been eliminated! The day is saved... ###"
                "\n************************************************************";
        return true;
    }
    return false;
}

void AntsVsBees::newBee() {
    cout << "\nA new Bee joins the fight...\n";
    new Bee(BugBoard::boardSize-1);
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


