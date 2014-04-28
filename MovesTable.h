//
//  MovesTable.h
//  Sudoku
//
//  Created by Nick Scoliard on 4/28/14.
//  Copyright (c) 2014 Nick Scoliard. All rights reserved.
//

#ifndef __Sudoku__MovesTable__
#define __Sudoku__MovesTable__

#include <iostream>
#include <vector>
#include "Sudoku.h"


class MovesTable {
    int size;
    
public:
    vector <vector <vector <int> > > moveTable;
    MovesTable(int);
    ~MovesTable();
    vector<int> LegalMoves(int, int);
    void InitializeTable(Board*);
    void UpdateRow(int, int);
    void UpdateColumn(int, int);
    void UpdateBox(int, int, int);
    void setValue(Board*, int, int, int);
};


#endif /* defined(__Sudoku__MovesTable__) */
