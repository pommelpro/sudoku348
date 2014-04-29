//
//  BackTracking.h
//  Sudoku
//
//  Created by Nick Scoliard on 4/28/14.
//  Copyright (c) 2014 Nick Scoliard. All rights reserved.
//

#ifndef __Sudoku__BackTracking__
#define __Sudoku__BackTracking__

#include "Sudoku.h"//;
#include "MovesTable.h"//;

bool BackTrack(Board*);

bool BackTrackRecur(Board*, MovesTable);

#endif /* defined(__Sudoku__BackTracking__) */
