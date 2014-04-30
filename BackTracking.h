//
//  BackTracking.h
//  Sudoku


#ifndef __Sudoku__BackTracking__
#define __Sudoku__BackTracking__

#include "Sudoku.h"//;
#include "MovesTable.h"//;

bool BackTrack(Board*);

bool BackTrackRecur(Board*, MovesTable);

#endif /* defined(__Sudoku__BackTracking__) */
