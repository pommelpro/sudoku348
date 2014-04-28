//
//  MovesTable.cpp
//  Sudoku
//
//  Created by Nick Scoliard on 4/28/14.
//  Copyright (c) 2014 Nick Scoliard. All rights reserved.
//

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
                moveTable[r][j].erase(moveTable[r][j].begin() + k);
        }
    }
}

void MovesTable::UpdateColumn(int con, int c) {
    for(int i = 0; i < size; i++) {
        for (int k = moveTable[i][c].size() - 1; k > 0; k--) {
            if(moveTable[i][c][k] == con)
                moveTable[i][c].erase(moveTable[i][c].begin() + k);
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
            for (int k = (int) moveTable[i][j].size() - 1; k > 0; k--) {
                if (moveTable[i][j][k] == con) {
                     moveTable[i][j].erase(moveTable[i][j].begin() + k);
                }
               
            }
        }
    }
}

void MovesTable::setValue(Board* b, int r, int c, int con) {
    b->set_square_value(r + 1, c + 1, con);
    moveTable[r][c].clear();
    moveTable[r][c].push_back(-1);
}

bool MovesTable::MinRemaingValue(int &r, int &c) {
    int row = 0;
    int col = 0;
  
    bool worked = false;
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (moveTable[i][j][0] != -1 && !worked) {
                worked = true;
                row = i;
                col = j;
            }
            else if (moveTable[i][j][0] != -1 && worked && moveTable[i][j].size() < moveTable[row][col].size()) {
                row = i;
                col = j;
            }
        }
    }
    
    r = row;
    c = col;
    
    return worked;
}