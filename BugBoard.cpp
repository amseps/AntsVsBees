//
// Created by AM on 11/2/2020.
//

#include "BugBoard.h"

int BugBoard::antFood = 50;///// ???????? ok? ? ?
vector<vector<Bug>> BugBoard::bugBoard = *new vector<vector<Bug>>();

BugBoard::BugBoard() {
    BugBoard::bugBoard.reserve(boardSize);
    BugBoard::antFood = 50;
}
