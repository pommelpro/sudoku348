/* 
 * File:   Sudoku.h
 * Author: Nick
 *
 * Created on April 22, 2014, 1:18 PM
 */

#ifndef SUDOKU_H
#define	SUDOKU_H

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
};


#endif	/* SUDOKU_H */

