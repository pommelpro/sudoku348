/* 
 * File:   MovesTable.h
 * Author: Nick
 *
 * Created on April 22, 2014, 1:30 PM
 */
#include <vector>
#include "Sudoku.h"
#ifndef MOVESTABLE_H
#define	MOVESTABLE_H


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
    
    
};


#endif	/* MOVESTABLE_H */

