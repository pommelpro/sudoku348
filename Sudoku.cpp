//
//  Sudoku.cpp
//  Sudoku


#include<iostream>
#include<fstream>
#include<sstream>
#include <stdio.h>
#include <stdlib.h>
#include "Sudoku.h"
#include<string>
#include<math.h>

using namespace std;

Board::Board(int d) {
	if(d > 62)
		throw ("Dimensions must be at most 62");
	dim = d;
	cells = new int*[dim];
	for(int i=0; i<dim;i++) {
		cells[i] = new int[dim];
		for(int j=0; j<dim;j++)
			cells[i][j] = 0;
	}
	totalChecks = 0;
    million = false;
    timeStart = time(nullptr);
}

Board::~Board() {
	for(int i=0; i<dim;i++) {
		delete [] cells[i];
	}
	delete [] cells;
}

string Board::toString() {
	stringstream s;
	for(int i=0; i<dim;i++) {
		for(int j=0; j<dim; j++) {
			if(cells[i][j]==0)
				s << '_';
			else
				s << cells[i][j];
		}
		s << endl;
	}
	return s.str();
}

void Board::set_square_value(int row, int col, int val) {
	cells[row-1][col-1] = val;
    totalChecks++;
    if (totalChecks > 15000000) {
        string error = "\nTerminated after ";
        error += to_string(totalChecks);
        error += " consistency checks  ";
        error += "\nTime Taken: ";
        time_t timeEnd = time(nullptr);
        time_t timeTaken = timeEnd - timeStart;
        error += to_string(timeTaken/60);
        error += " minutes";
        cout << error <<'\n';
        throw (error);
    }
    //cout << "Total Check: " << totalChecks << '\n';
}

int Board::get_square_value(int row, int col) {
	return cells[row-1][col-1];
}

Board * Board::fromFile(string inFileName) {
    string line;
    ifstream inFile (inFileName.c_str());
    Board * out;
    if (inFile.is_open()) {
        getline (inFile,line);
        int d = atoi(line.c_str());
        out = new Board(d);
        getline (inFile, line);
        int numVals = atoi(line.c_str());
        for(int i=0; i<numVals;i++) {
            string field;
            getline (inFile,field, '\t');
            int row = atoi(field.c_str());
            getline (inFile,field, '\t');
            int col = atoi(field.c_str());
            getline (inFile,field);
            int val = atoi(field.c_str());
            out->set_square_value(row, col, val);
        }
    }
    inFile.close();
    return out;
}

bool Board::checkForVictory() {
	unsigned long victory = 0;
	//optimization: check if it's filled:
	for(int i=1; i<dim+1;i++)
		for(int j=1;j<dim+1;j++)
			if(this->get_square_value(i,j)==0)
				return false;
	for(int i=1; i<dim+1; i++)
		victory += 1 << i;
	//check rows and columns:
	for(int i=1; i<dim+1;i++) {
		unsigned long rowTotal = 0;
		unsigned long columnTotal = 0;
		for(int j=1; j<dim+1; j++) {
			rowTotal += 1 << this->get_square_value(i, j);
			columnTotal += 1 << this->get_square_value(j, i);
		}
		if(rowTotal!=victory||columnTotal!=victory)
			return false;
	}
	int dimsqrt = (int)(sqrt((double)dim));
	//check little squares:
	cout << "checking little squares" << endl;
	for(int i=0;i<dimsqrt;i++) {
		for(int j=0;j<dimsqrt;j++) {
			unsigned long squareTotal = 0;
			for(int k=1; k<dimsqrt+1;k++) {
				for(int m=1; m<dimsqrt+1;m++) {
					squareTotal += 1 << this->get_square_value(i*dimsqrt+k, j*dimsqrt+m);
					cout << this->get_square_value(i*dimsqrt+k, j*dimsqrt+m);
				}
				cout << endl;
			}
			if(squareTotal != victory)
				return false;
		}
	}
	return true;
}

bool Board::checkEmpty() {
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            if (get_square_value(i + 1, j + 1) != 0) {
                return true;
            }
        }
    }
    
    return false;
}



