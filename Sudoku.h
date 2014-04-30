//
//  Sudoku.h
//  Sudoku


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
    bool million;
	int dim;
	int ** cells;
	long totalChecks;
    time_t timeStart;
public:
	Board (int);
	~Board();
	string toString();
	void set_square_value(int,int,int);
	int get_square_value(int,int);
	static Board* fromFile(string);
	bool checkForVictory();
	int get_dim() {return dim;}
    long get_totalChecks() {return totalChecks;}
    bool checkEmpty();
};

#endif /* defined(__Sudoku__Sudoku__) */
