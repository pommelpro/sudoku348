#include<iostream>
#include<fstream>
#include<sstream>
#include <stdio.h>
#include <stdlib.h>
#include "Sudoku.h"
#include "MovesTable.h"
#include<string>
#include<math.h>
#include <vector>

using namespace std;

MovesTable::MovesTable(int s) {
    if (size != 4 || size != 9 || size != 16 || size != 25)
        throw("Size must be 4, 9, 16, or 25");
    size = s;
    moveTable = new int*[size];
    for(int i = 0; i < size; i++) {
        moveTable[i] = new int[size];
        for(int j = 0; j < size; j++) {
            moveTable[i][j] = vector<int> legalMoves(size);
            for(int k = 0; k < size; k++) {
                moveTable[i][j][k] = k + 1;
            }
        }
    }              
}   

MovesTable::~MovesTable() {
    delete moveTable;
}

MovesTable::LegalMoves(int r, int c) {
    return moveTable[r][c];
}
