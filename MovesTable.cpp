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
#include  <algorithm>
#include <cmath>

using namespace std;


MovesTable::MovesTable(int s) {
    cout << "hey";
    size = s;
    moveTable.resize(size);
    for(int i = 0; i < size; i++) {
        moveTable[i].resize(size);
        for(int j = 0; j < size; j++) {
            for(int k = 0; k < size; k++) {
                moveTable[i][j].push_back(k + 1);
            }
        }
    }              
}   

MovesTable::~MovesTable() {
    
}

vector<int> MovesTable::LegalMoves(int r, int c) {
    return moveTable[r][c];
}

void MovesTable::InitializeTable(Board* b) {
    cout << "hey";
    for (int i = 0; i < size; i++) {
        int* holder = new int[size];
        int* colArray = new int[size];
        int c = 0;
        for (int j = 0; j < size; j++) {
            int test = b->get_square_value(i + 1, j + 1);
            if(test > 0) {
                holder[c] = test;
                colArray[c] = j;
                c++;
            }
        }
        
        for (int j = 0; j < size; j++) {
            if(holder[j]) {
                UpdateRow(holder[j], i);
                UpdateColumn(holder[j], colArray[j]);
                UpdateBox(holder[j], i, colArray[j]);
            }
        }
        
    }
}

void MovesTable::UpdateRow(int con, int r) {
    for(int j = 0; j < size; j++) {
        for(int k = moveTable[r][j].size() - 1; k > 0 ; k--) {
            if(moveTable[r][j][k] == con)
                moveTable.erase(moveTable.begin() + k);
        }
    }
}

void MovesTable::UpdateColumn(int con, int c) {
    for(int i = 0; i < size; i++) {
        for (int k = moveTable[i][c].size() - 1; k > 0; k--) {
            if(moveTable[i][c][k] == con)
                moveTable.erase(moveTable.begin() + k);
        }
    }
}

void MovesTable::UpdateBox(int con, int r, int c) {
    int sq = (int) sqrt(size);
    int row = r/sq;
    row *= sq;
    int col = c/sq;
    col *= sq;
    
    for (int i = row; i < row + sq; i++) {
        for (int j = col; j < col + sq; j++) {
            for (int k = moveTable[i][j].size() - 1; k > 0; k--) {
                moveTable.erase(moveTable.begin() + k);
            }
        }
    }
}