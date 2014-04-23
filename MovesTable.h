/* 
 * File:   MovesTable.h
 * Author: Nick
 *
 * Created on April 22, 2014, 1:30 PM
 */

#ifndef MOVESTABLE_H
#define	MOVESTABLE_H


class MovesTable {
    int size;
    int** moveTable;
public:
    MovesTable(int);
    ~MovesTable();
    vector<int> LegalMoves(int, int);
    void UpdateMoves(int, int);
    
    
};


#endif	/* MOVESTABLE_H */

