//
// Created by AM on 10/29/2020.
//

#include "Bug.h"


Bug::Bug() {
    myID = BUG;
    int armor = -1;
}

void Bug::takeDamage(int dam){
    std::cout << "*HIT: " << dam << "*";
    armor -= dam;
    if(armor <=0) die();
}
void Bug::die() {
    // can't include bugboard hmm can't fix hmm
}

std::string Bug::print() {
    return "[BUG (" + std::to_string(armor) +"/-1)]";
}