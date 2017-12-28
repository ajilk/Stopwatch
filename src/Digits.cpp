#include "Digits.h"

Digits::Digits(){	
	ifstream infile;
	string filename;
	char ch;
	for(int i=0; i<9; i++){
		filename = "../digits/" + std::to_string(i) + ".txt";
		infile.open(filename);
		if(!infile.is_open()){
			mvprintw(0,0,"ERROR: Unable to open file %d.txt",i);
			refresh();
			getch();
		}
		while(infile>>ch){
			number[i].push_back(ch);
		}
	}
}

void Digits::print(WINDOW* window, int digit, int start_y, int start_x){
	int offset_x = 0;
	int offset_y = 0;
	for(int i=0; i<number[digit].size(); i++){
		mvwprintw(window, start_y + offset_y, start_x+offset_x, "%c", number[digit].at(i));
		offset_x++;
		if(offset_x == 7){
			offset_x = 0;
			offset_y++;
		}
	}

}
