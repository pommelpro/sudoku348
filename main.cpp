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
    Board * b = Board::fromFile("4x4.txt");
    
    b->set_square_value(1, 2, 2);
    b->set_square_value(2, 4, 2);
    b->set_square_value(3, 2, 3);
    b->set_square_value(3, 3, 4);
    b->set_square_value(4, 1, 4);
    
    bool check = BackTrack(b);
    
    if (check) {
        cout << "yeeeeee" << '\n';
        cout << b->toString();
    }
    
}

