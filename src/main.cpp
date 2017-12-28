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
	wrefresh(scoreWindow); wrefresh(timeWindow);	

	auto start = steady_clock::now();
	auto end = steady_clock::now();


	int ch = wgetch(timeWindow);
	while(ch != 'X'){
		start = steady_clock::now();	
		nodelay(stdscr, true);	
		while(!screen.kbhit()){
			end = steady_clock::now();
			mvwprintw(timeWindow,1,1,"%.3f", duration_cast<duration<float> >(end-start).count());
			screen.drawBorder(timeWindow);
			screen.drawBorder(scoreWindow);
			wrefresh(timeWindow);
			digits.print(timeWindow, 0, 10,10);
		}
		nodelay(stdscr, false);
		end = steady_clock::now();
		mvwprintw(timeWindow, 1,1,"%.3f", std::chrono::duration_cast<std::chrono::duration<float> >(end-start).count());	
		mvwprintw(scoreWindow, 1,1,"%.3f", std::chrono::duration_cast<std::chrono::duration<float> >(end-start).count());
		wrefresh(timeWindow); wrefresh(scoreWindow);
		wgetch(timeWindow);

		ch = wgetch(timeWindow);	
	}
	mvprintw(0,0,"STOPPED: Press any key to quit application");
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
		endwin();
	return 0;	
}*/
