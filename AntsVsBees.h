//
// Created by AM on 10/29/2020.
//

#ifndef ANTSVSBEES_ANTSVSBEES_H
#define ANTSVSBEES_ANTSVSBEES_H

#include "Bug.h"
#include "BugBoard.h"

class AntsVsBees {

private:
    bool runTurn();
    void displayStats();
    void displayBoard();
    void runActions();
    void options();
    bool isGameOver();

    int input_getLineInt();

    int turn = 0;

public:
    void runGame();

    ~AntsVsBees();
    AntsVsBees();
    AntsVsBees(AntsVsBees & in);
    AntsVsBees & operator=(AntsVsBees & right);
};


#endif //ANTSVSBEES_ANTSVSBEES_H
