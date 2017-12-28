#ifndef DIGITS_H
#define DIGITS_H

#include <ncurses.h>
#include <fstream>
#include "Coordinate.h"
#include <vector>

using namespace std;

class Digits{
private:
	vector<char> number[9]; 
public:
	Digits();
	void print(WINDOW* window, int number, int start_y, int start_x);
};

#endif
