//
//  BackTracking.cpp
//  Sudoku
//
//  Created by Nick Scoliard on 4/28/14.
//  Copyright (c) 2014 Nick Scoliard. All rights reserved.
//

#include "BackTracking.h"

#include <iostream>
#include "Sudoku.h"
#include "MovesTable.h"


bool BackTrack(Board* b) {
    MovesTable mt = MovesTable(b->get_dim());
    
    mt.InitializeTable(b);
    
    return BackTrackRecur(b, mt);
}

bool BackTrackRecur(Board* b, MovesTable mt) {
    if (b->checkForVictory()) {
        return true;
    }
    

    int row, col;
    
    //mt.MinRemainingValue(row, col);
    
    mt.NextRemainingValue(row, col);
    
    
    
    vector<int> testVec = mt.LegalMoves(row, col);
    
    vector<int>leastVec = mt.LeastConstraingVal(row, col);
    
    
    for (int i = 0; i < leastVec.size(); i++) {
        cout << "Row: " << row << " Col: " << col << " Num: " << testVec[i] << '\n';
        
        mt.setValue(b, row, col, testVec[i]);
        
        if (!mt.ForwardChecking()) {
             b->set_square_value(row + 1, col + 1, 0);
            return false;
        }
        
        bool result = BackTrackRecur(b, mt);
        
        
        
        if (result) {
            return true;
        }
        
        
        b->set_square_value(row + 1, col + 1, 0);
        
        mt = MovesTable(b->get_dim());
        
        mt.InitializeTable(b);
    }
    
    Board emp = Board(b->get_dim());
    return false;
    
}