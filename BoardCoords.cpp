/* 
 * File:   BoardCoords.cpp
 * Author: Nick
 * 
 * Created on April 22, 2014, 4:19 PM
 */

#include "BoardCoords.h"

BoardCoords::BoardCoords() {
    col = 0;
    row = 0;
}

BoardCoords::BoardCoords(int r, int c) {
    row = r;
    col = c;
}

BoardCoords::~BoardCoords() {
}

