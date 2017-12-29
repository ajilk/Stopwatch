#include "Screen.h"

Screen::Screen(){
	initscr();
	getmaxyx(stdscr, rows, columns);
	curs_set(0);
	cbreak();
	noecho();
	use_default_colors();
//	border(ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE, 
//			ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);
	if(!has_colors()){
		clear();
		mvprintw(0,0,"ERROR: TERMINAL DOES NOT SUPPORT COLOR");
		refresh();
		getch();
		endwin();
		exit (EXIT_FAILURE);
	}else if(!can_change_color()){
		clear();
		mvprintw(0,0,"ERROR: TERMINAL CAN NOT CHANGE COLOR");
		refresh();
		getch();
		endwin();
		exit (EXIT_FAILURE);	
	}else
		start_color();
//	nodelay(stdscr, TRUE);
}

int Screen::getRows(){
	return rows;
}

int Screen::getColumns(){
	return columns;
}

bool Screen::kbhit(){
	int ch=getch();
	if(ch != ERR){
		ungetch(ch);
		return true;
	}
	else
		return false;
}

WINDOW* Screen::newWindow(int rows, int cols, int begin_x, int begin_y){
	WINDOW* window;
	if((window = newwin(rows, cols, begin_x, begin_y)) == NULL){
		mvprintw(0,0,"ERROR: Unable to create window");
		refresh();
		getch();
		endwin();
		exit(EXIT_FAILURE);
	}
	wborder(window, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE, ACS_ULCORNER, 
					ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);
	return window;
}

void Screen::delWindow(WINDOW* window){
	delwin(window);
	clear();
	refresh();
}

void Screen::drawBorder(WINDOW* window){
	wborder(window, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE, ACS_ULCORNER,
				ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);
	wrefresh(window);
}

Screen::~Screen(){
	clear();
	mvprintw(0,0,"STOPPED: Press any key to quit application");
	refresh();
	nodelay(stdscr, FALSE);
	getch();
	endwin();
}
