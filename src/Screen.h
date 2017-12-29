#ifndef SCREEN_H
#define SCREEN_H

#include <ncurses.h>
#include <stdlib.h>	//exit()
#include <vector>
#include <fstream>

using namespace std;
class Screen{
private:
	int rows;
	int columns;
	vector<char> beginMessage;
	vector<char> endMessage;
	vector<char> confirmMessage;
public:
	Screen();
	int getRows();
	int getColumns();
	vector<char> getBeginMessage() { return beginMessage; }
	vector<char> getEndMessage() { return endMessage; }
	vector<char> getConfirmMessage() { return confirmMessage; }
	bool kbhit();
	WINDOW* newWindow(int rows, int cols, int start_y, int start_x);
	void delWindow(WINDOW* window);
	void drawBorder(WINDOW *window);
	void print(WINDOW* window, vector<char> message, int start_y, int start_x);
	~Screen();
};

#endif
