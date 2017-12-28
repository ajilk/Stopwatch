#ifndef SCREEN_H
#define SCREEN_H

#include <ncurses.h>
#include <stdlib.h>	//exit()

class Screen{
private:
	int rows;
	int columns;
public:
	Screen();
	int getRows();
	int getColumns();
	bool kbhit();
	WINDOW* newWindow(int rows, int cols, int begin_y, int begin_x);
	void delWindow(WINDOW* window);
	~Screen();
};

#endif
