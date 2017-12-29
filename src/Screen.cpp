#include "Screen.h"

Screen::Screen(){
	initscr();
	getmaxyx(stdscr, rows, columns);
	curs_set(0);
	cbreak();
	noecho();
	use_default_colors();
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
	char ch;
	ifstream infile;
	infile.open("../digits/beginMessage.txt");
	while(infile.get(ch)){
		beginMessage.push_back(ch);	
	}infile.close();
	
	infile.open("../digits/endMessage.txt");
	while(infile.get(ch)){
		endMessage.push_back(ch);	
	}infile.close();
	
	infile.open("../digits/confirmMessage.txt");
	while(infile.get(ch)){
		confirmMessage.push_back(ch);	
	}infile.close();

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

void Screen::print(WINDOW* window, vector<char> message, int start_y, int start_x){
	wclear(window);
	int i=0, j=0, count=0;
	while(count < message.size()){
		if(message[count] == '\n'){
			i++;
			j=0;
		}
		else
			j++;
		mvwprintw(window, start_y+i, start_x+j, "%c", message[count]);
		count++;
	}
}

Screen::~Screen(){
	clear();
	print(stdscr, endMessage, 20, 70);		
	refresh();
	nodelay(stdscr, FALSE);
	getch();
	endwin();
}
