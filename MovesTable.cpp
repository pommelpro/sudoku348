//
//  MovesTable.cpp
//  Sudoku


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
#include <algorithm>
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
        for (int j = 0; j < size; j++) {
            int con = b->get_square_value(i + 1, j + 1);
            if (con != 0) {
                setValue(b, i, j, con);
            }
        }
    }
    
    /*
    for (int i = 0; i < size; i++) {
        int* holder = (int *)malloc(size * sizeof(int));
        int* colArray = (int *)malloc(size * sizeof(int));
        int c = 0;
        for (int j = 0; j < size; j++) {
            int test = b.get_square_value(i + 1, j + 1);
            if(test > 0) {
                holder[c] = test;
                colArray[c] = j;
                c++;
            }
        }
        
        for (int j = 0; j < size; j++) {
            int constraint = holder[j];
            if(constraint) {
                UpdateRow(constraint, i);
                UpdateColumn(constraint, colArray[j]);
                UpdateBox(constraint, i, colArray[j]);
            }
        }
        
    }*/
}

void MovesTable::UpdateRow(int con, int r) {
    for(int j = 0; j < size; j++) {
        for(int k = (int) moveTable[r][j].size() - 1; k >= 0 ; k--) {
            if(moveTable[r][j][k] == con)
                moveTable[r][j].erase(moveTable[r][j].begin() + k);
        }
    }
}

void MovesTable::UpdateColumn(int con, int c) {
    for(int i = 0; i < size; i++) {
        for (int k = (int) moveTable[i][c].size() - 1; k >= 0; k--) {
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
            for (int k = (int) moveTable[i][j].size() - 1; k >= 0; k--) {
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
    
    
    UpdateRow(con, r);
    UpdateColumn(con, c);
    UpdateBox(con, r, c);
}

bool MovesTable::MinRemainingValue(int &r, int &c) {
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
            
            else if (moveTable[i][j][0] != -1 && moveTable[i][j].size() == moveTable[row][col].size()) {
                int newTest = Constraints(i, j);
                int oldTest = Constraints(row, col);
                
                if (newTest > oldTest) {
                    row = i;
                    col = j;
                }
            }
        }
    }
    
    r = row;
    c = col;
    
    return worked;
}

int MovesTable::Constraints(int r, int c) {
    int count = 0;
    //Row Search
    for (int j = 0; j < size; j++) {
        if (moveTable[r][j][0] != -1) {
            count++;
        }
    }
    
    //Column Search
    for (int i = 0; i < size; i++) {
        if (moveTable[i][c][0] != -1) {
            count++;
        }
    }
    
    //Box Search
    int sq = (int) sqrt(size);
    int row = r/sq;
    row *= sq;
    int col = c/sq;
    col *= sq;
    
    for (int i = row; i < row + sq; i++) {
        for (int j = col; j < col + sq; j++) {
            if(i != r && j != c && moveTable[i][j][0] != -1)
                count++;
        }
    }
    
    return count;
}

bool MovesTable::ForwardChecking() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (moveTable[i][j].size() == 0) {
                return false;
            }
        }
    }
    
    return true;
}

vector<int> MovesTable::LeastConstraingVal(int r, int c) {
    if (moveTable[r][c].size() < 2) {
        vector<int> test;
        test.push_back(moveTable[r][c][0]);
        return test;
    }
    
    vector<int> best;
    best.resize(moveTable[r][c].size());
    vector<int> constArr;
    constArr.resize(moveTable[r][c].size());
    
    
    
    for (int count = 0; count < moveTable[r][c].size(); count++) {
        int con = moveTable[r][c][count];
        int testConst = 0;
        
        //Row Search
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < moveTable[r][j].size(); k++) {
                if (moveTable[r][j][k] == con) {
                    testConst++;
                    break;
                }
            }
        }
        
        //Column Search
        for (int i = 0; i < size; i++) {
            for (int k = 0; k < moveTable[i][c].size(); k++) {
                if (moveTable[i][c][k] == con) {
                    testConst++;
                    break;
                }
            }
        }
        
        //Box Search
        int sq = (int) sqrt(size);
        int row = r/sq;
        row *= sq;
        int col = c/sq;
        col *= sq;
        
        for (int i = row; i < row + sq; i++) {
            for (int j = col; j < col + sq; j++) {
                for (int k = 0; k < moveTable[i][j].size() ; k++) {
                    if (i != r && j != c && moveTable[i][j][k] == con) {
                        testConst++;
                        break;
                    }
                }
            }
        }
        
        if (count == 0) {
            best[0] = con;
            constArr[0] = testConst;
        }
        else {
            for (int i = 0; i <= count; i++) {
                if (testConst < constArr[i] || constArr[i] == 0) {
                    best.insert(best.begin() + i, con);
                    best.pop_back();
                    constArr.insert(constArr.begin() + i, testConst);
                    constArr.pop_back();
                    break;
                    
                }
            }
        }

    }
    
    return best;
}

bool MovesTable::NextRemainingValue(int &r, int &c) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (moveTable[i][j].size() == 0) {
                return false;
            }
            if (moveTable[i][j].size() > 0 && moveTable[i][j][0] != -1) {
                r = i;
                c = j;
                return true;
            }
        }
    }
    
    return false;
}