#include <ncurses.h>
#include <chrono>
bool kbhit() {
	nodelay(stdscr, TRUE);
	int ch = getch();
    	if (ch != ERR) {
       		//ungetch(ch);
    		return true;
  	 } else {
     		return false;
    	}
	nodelay(stdscr, FALSE);
}

int main()
{	
	initscr();			/* Start curses mode		*/
	start_color();
	curs_set(0);
	noecho();
	cbreak();
	int i=0;
	while(getch() == ERR){
		init_color(COLOR_GREEN, i*3, i*3, i*3);
		init_pair(1, COLOR_BLACK, COLOR_GREEN);
		attron(COLOR_PAIR(1));
		mvprintw(0,0," "); refresh(); i++;
		attroff(COLOR_PAIR(2));
		nodelay(stdscr, TRUE);
	}
	auto start = std::chrono::steady_clock::now();
	auto end = std::chrono::steady_clock::now();
	nodelay(stdscr, TRUE);
	do{
		end = std::chrono::steady_clock::now();
		mvprintw(0,0,"%.3f", std::chrono::duration_cast<std::chrono::duration<float> >(end-start).count());
		refresh();
	}while(getch() == ERR);
	nodelay(stdscr, FALSE);
	end = std::chrono::steady_clock::now();
	mvprintw(0,0,"%.3f", std::chrono::duration_cast<std::chrono::duration<float> >(end-start).count());
	refresh();
	getch();
	endwin();			/* End curses mode 		*/
	return 0;
}
