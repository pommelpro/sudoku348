//
//  main.cpp
//  Sudoku
//
//  Created by Nick Scoliard on 4/28/14.
//  Copyright (c) 2014 Nick Scoliard. All rights reserved.
//

#include <iostream>
using namespace std;
#include "MovesTable.h"

/*
 *
 */

int main(int argc, char* argv[])
{
 
    MovesTable mt = MovesTable(4);
   
    Board * b = new Board(4);
    mt.setValue(b, 0, 0, 3);
    mt.setValue(b, 0, 1, 2);
    
    mt.InitializeTable(b);
    
    int row, col;
    bool check = mt.MinRemaingValue(row, col);
    if(check)
        cout << "yee" << '\n';
    cout << "Row: " << row << "   Col: " << col << '\n';
    
    
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            for(int k = 0; k < mt.moveTable[i][j].size(); k++) {
                cout << mt.moveTable[i][j][k];
            }
            cout << '\n';
        }
    }
}

