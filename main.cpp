/* 
 * File:   main.cpp
 * Author: Nick
 *
 * Created on April 21, 2014, 2:34 PM
 */

using namespace std;
#include "MovesTable.h"

/*
 * 
 */

int main(int argc, char* argv[])
{
   
    MovesTable mt = MovesTable(4);
    Board * b = new Board(4);
     b->set_square_value(1, 1, 3);
     b->set_square_value(1, 2, 2);
     
    mt.InitializeTable(b);
    
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            for(int k = 0; k < 4; k++) {
                cout << mt.moveTable[i][j][k];                     
            }
            cout << '\n';
        }
    }
}
