#ifndef DIGITS_H
#define DIGITS_H

#include <ncurses.h>
#include <fstream>
#include "Coordinate.h"
#include <vector>

using namespace std;

class Digits{
private:
	vector<char> number[11]; 
public:
	Digits();
	void print(WINDOW* window, int number, int start_y, int start_x);
	void printAll(WINDOW* window, vector<int> nums, int start_y, int start_x);
	vector<int> convert(float number);
};

#endif
