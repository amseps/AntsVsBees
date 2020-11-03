//
// Created by AM on 10/29/2020.
//

#include "Bug.h"


Bug::Bug() {
    myID = BUG;
    int armor = -1;
}

void Bug::takeDamage(int dam){
    armor -= dam;
    if(dam <=0) die();
}
void Bug::die() {

}

std::string Bug::print() {
    return "[BUG (" + std::to_string(armor) +"/-1)]";
}