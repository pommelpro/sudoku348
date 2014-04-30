//
//  BackTracking.cpp
//  Sudoku


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
    
    //MRV + MCV Heuristic
    
    mt.MinRemainingValue(row, col);
    
    //Without MRV heuristic
    
    //if(!mt.NextRemainingValue(row, col)) {
    //    return false;
    //}
    
    
    //Without LCV heuristic
    //vector<int> testVec = mt.LegalMoves(row, col);
    
    //LCV heuristic
    vector<int>leastVec = mt.LeastConstraingVal(row, col);
    
    
    for (int i = 0; i < leastVec.size(); i++) {
        
        
        mt.setValue(b, row, col, leastVec[i]);
    
        
        
        
        //Forward Checking
        if (!mt.ForwardChecking()) {
            b->set_square_value(row + 1, col + 1, 0);
            mt = MovesTable(b->get_dim());
            mt.InitializeTable(b);
        
            continue;
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