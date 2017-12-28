#include <ncurses.h>
#include <chrono>
using namespace std::chrono;
bool kbhit(){
	int ch = getch();
	if(ch == ERR)
		return false;
	else{
		//ungetch(ch); 
		return true;
	}
}
int main()
{
	initscr();
	noecho();
	cbreak();
	curs_set(0);
	
	auto start = steady_clock::now();
	auto end = steady_clock::now();

	mvprintw(0,0,"Press any key to start");
	getch(); 
	clear();
	start = steady_clock::now();	
	nodelay(stdscr, true);	
	while(!kbhit()){
		end = steady_clock::now();
		mvprintw(0,0,"%.3f", duration_cast<duration<float> >(end-start).count());
		refresh();
	}
	nodelay(stdscr, false);
	end = steady_clock::now();
	mvprintw(0,0,"%.3f", std::chrono::duration_cast<std::chrono::duration<float> >(end-start).count());	
	refresh();
	getch();
	endwin();
	return 0;	
}
