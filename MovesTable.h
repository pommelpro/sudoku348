//
//  MovesTable.h
//  Sudoku


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
    void setValue(Board* b, int, int, int);
    bool MinRemainingValue(int &r, int &c);
    int Constraints(int, int);
    bool ForwardChecking();
    int getSize() { return size; };
    vector<int> LeastConstraingVal(int, int);
    bool NextRemainingValue(int &r, int &c);
};


#endif /* defined(__Sudoku__MovesTable__) */
