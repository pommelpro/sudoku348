/* 
 * File:   main.cpp
 * Author: Nick
 *
 * Created on April 21, 2014, 2:34 PM
 */

using namespace std;
#include "Sudoku.h"

/*
 * 
 */
void testBasics() {
	Board * b = new Board(4);
	b->set_square_value(1, 1, 1);
	b->set_square_value(1, 2, 2);
	b->set_square_value(1, 3, 3);
	b->set_square_value(1, 4, 4);
	b->set_square_value(2, 1, 3);
	b->set_square_value(2, 2, 4);
	b->set_square_value(2, 3, 1);
	b->set_square_value(2, 4, 2);
	b->set_square_value(3, 1, 4);
	b->set_square_value(3, 2, 3);
	b->set_square_value(3, 3, 2);
	b->set_square_value(3, 4, 1);
	b->set_square_value(4, 1, 2);
	b->set_square_value(4, 2, 1);
	b->set_square_value(4, 3, 4);
	b->set_square_value(4, 4, 3);
	cout << b->toString();
	cout << b->checkForVictory();
	char a;
	cin >> a;
}

int main(int argc, char* argv[])
{
	testBasics();
	return 0;
}
