

#include <iostream>
#include "AntsVsBees.h"

using namespace std;

void runTests(){

}

int main() {
    std::cout << "Hello, World!" << std::endl;
    cout << BugBoard::boardSize << " " << BugBoard::antFood;
    AntsVsBees *a = new AntsVsBees();
    a->runGame();
    return 0;
}