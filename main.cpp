//
//  main.cpp
//  Sudoku

#include <iostream>
#include <fstream>
using namespace std;
#include "BackTracking.h"

/*
 *
 */

int main(int argc, char* argv[])
{
    Board * b = Board::fromFile("25x25.txt");
    
    cout << b->toString() << '\n';
    
    bool check = BackTrack(b);
    
    if (check) {
        cout << b->toString();
        cout << b->get_totalChecks() << '\n';
    }
    
}

