#include <ncurses.h>
#include <chrono>
#include "Screen.h"
#include "Digits.h"
using namespace std::chrono;
int main()
{
	Screen screen;
	Digits digits;
	WINDOW* scoreWindow;
	WINDOW* timeWindow;
	scoreWindow = screen.newWindow(40, 40, 5, 8);
	timeWindow = screen.newWindow(40, 115, 5, 55);
	digits.print(timeWindow, 0, 5, 7);
	wrefresh(timeWindow); wrefresh(scoreWindow);
	wgetch(timeWindow);
	return 0;
}
/*	
	WINDOW* timeWindow;
	timeWindow = newwin(10,20,10,10);
	wborder(timeWindow, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE,
			ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);
	mvwprintw(timeWindow, 0,0, "time Window");
	wrefresh(timeWindow);
	wgetch(timeWindow);
	auto start = steady_clock::now();
	auto end = steady_clock::now();

	mvwprintw(timeWindow, 0,0,"Press any key to start");
	wgetch(timeWindow); 
	wclear(timeWindow);
	start = steady_clock::now();	
	nodelay(stdscr, true);	
	while(!kbhit()){
		end = steady_clock::now();
		mvwprintw(timeWindow,0,0,"%.3f", duration_cast<duration<float> >(end-start).count());
		wrefresh(timeWindow);
	}
	nodelay(stdscr, false);
	end = steady_clock::now();
	mvwprintw(timeWindow, 0,0,"%.3f", std::chrono::duration_cast<std::chrono::duration<float> >(end-start).count());	
	wrefresh(timeWindow);
	wgetch(timeWindow);
	endwin();
	return 0;	
}*/
