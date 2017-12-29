#include <ncurses.h>
#include <chrono>
#include "Screen.h"
#include "Digits.h"
#include "Stats.h"
using namespace std::chrono;

int main()
{
	Screen screen;
	Digits digits;
	Stats stats;
	WINDOW* scoreWindow;
	WINDOW* timeWindow;
	scoreWindow = screen.newWindow(40, 40, 5, 8);
	timeWindow = screen.newWindow(40, 115, 5, 55);
	screen.print(timeWindow, screen.getBeginMessage(), 20, 40);
	screen.drawBorder(timeWindow);
	wrefresh(scoreWindow);
	wrefresh(timeWindow);

	bool confirmed = false;
	while(!confirmed){
		int ch = wgetch(timeWindow);
		wclear(timeWindow);
		while(ch != 'q' && ch != 'Q'){
			wclear(timeWindow);
			float currentSolveTime;
			auto start = steady_clock::now();
			auto end = steady_clock::now();
			nodelay(stdscr, true);	
			while(!screen.kbhit()){
				end = steady_clock::now();
				currentSolveTime = duration_cast< duration<float> >(end-start).count();
				digits.printAll(timeWindow, digits.convert(currentSolveTime), 10, 10);
				stats.print(scoreWindow, 2, 8);
				screen.drawBorder(timeWindow);	
				screen.drawBorder(scoreWindow);
				wrefresh(timeWindow);
			}
			nodelay(stdscr, false);
			wgetch(timeWindow);
			stats.add(currentSolveTime);
			stats.print(scoreWindow, 2, 8);
			wrefresh(scoreWindow);
			ch = wgetch(timeWindow);	
		}
		screen.print(timeWindow, screen.getConfirmMessage(), 20, 40);
		screen.drawBorder(timeWindow);
		ch = getch();
		if(ch == 'y' || ch == 'Y')
			confirmed = true;
		else{
			confirmed = false;
			screen.print(timeWindow, screen.getBeginMessage(), 20, 40);
			screen.drawBorder(timeWindow);
			wrefresh(timeWindow);
		}
	}
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
