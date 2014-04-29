//
//  Sudoku.h
//  Sudoku
//
//  Created by Nick Scoliard on 4/28/14.
//  Copyright (c) 2014 Nick Scoliard. All rights reserved.
//

#ifndef __Sudoku__Sudoku__
#define __Sudoku__Sudoku__

#include<iostream>
#include<fstream>
#include<sstream>
#include <stdio.h>
#include <stdlib.h>
#include "Sudoku.h"
#include<string>
#include<math.h>
using namespace std;

class Board {
	int dim;
	int ** cells;
	long totalChecks;
public:
	Board (int);
	~Board();
	string toString();
	void set_square_value(int,int,int);
	int get_square_value(int,int);
	static Board* fromFile(string);
	bool checkForVictory();
	int get_dim() {return dim;}
    bool checkEmpty();
};

#endif /* defined(__Sudoku__Sudoku__) */
