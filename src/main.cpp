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
	screen.print(timeWindow, screen.getBeginMessage(), 5, 8);
	screen.drawBorder(timeWindow);
	screen.drawBorder(scoreWindow);
	wrefresh(scoreWindow);
	wrefresh(timeWindow);

	bool confirmed = false;
	while(!confirmed){
		int ch = wgetch(timeWindow);
		while(ch != 'q' && ch != 'Q'){
			wclear(timeWindow);
			float currentSolveTime;
			auto start = steady_clock::now();
			auto end = steady_clock::now();
			nodelay(stdscr, true);	
			while(!screen.kbhit()){
				end = steady_clock::now();
				currentSolveTime = duration_cast< duration<float> >(end-start).count();
				digits.printAll(timeWindow, digits.convert(currentSolveTime), 15, 15);
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
			while(ch == 'x'){
				stats.removeLast();
				wclear(scoreWindow);
				stats.print(scoreWindow, 2, 8);
				screen.drawBorder(scoreWindow);
				wrefresh(scoreWindow);
				ch = wgetch(timeWindow);
			}
		}
//		ch = getch();
		if(ch == 'q' || ch == 'Q'){
			screen.print(timeWindow, screen.getConfirmMessage(), 2, 1);
			screen.drawBorder(timeWindow);
			screen.drawBorder(scoreWindow);
			wrefresh(timeWindow);
			wrefresh(scoreWindow);
			ch = wgetch(timeWindow);
			if(ch == 'y' || ch == 'Y')
				confirmed = true;
			else{
				confirmed = false;
				screen.print(timeWindow, screen.getBeginMessage(), 5, 8);
				screen.drawBorder(timeWindow);
				wrefresh(timeWindow);
			}
		}
	}
	return 0;
}
