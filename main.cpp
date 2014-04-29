//
//  main.cpp
//  Sudoku
//
//  Created by Nick Scoliard on 4/28/14.
//  Copyright (c) 2014 Nick Scoliard. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
#include "BackTracking.h"

/*
 *
 */

int main(int argc, char* argv[])
{
    Board * b = Board::fromFile("9x9.txt");
    
    cout << b->toString() << '\n';
    
    bool check = BackTrack(b);
    
    if (check) {
        cout << "yeeeeee" << '\n';
        cout << b->toString();
    }
    
}

