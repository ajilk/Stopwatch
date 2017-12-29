#include "Digits.h"

Digits::Digits(){	
	ifstream infile;
	string filename;
	char ch;
	for(int i=0; i<11; i++){
		filename = "../digits/" + std::to_string(i) + ".txt";
		infile.open(filename);
		if(!infile.is_open()){
			mvprintw(0,0,"ERROR: Unable to open file %d.txt",i);
			refresh();
			getch();
		}
		while(infile.get(ch)){
			if(ch != '\n') number[i].push_back(ch);
		}
		infile.close();
	}
}

void Digits::print(WINDOW* window, int digit, int start_y, int start_x){
	int offset_x = 0;
	int offset_y = 0;
	for(int i=0; i<number[digit].size(); i++){
		mvwprintw(window, start_y + offset_y, start_x+offset_x, "%c", number[digit].at(i));
		offset_x++;
		if(offset_x == 10){
			offset_x = 0;
			offset_y++;
		}
	}
	wrefresh(window);
}

void Digits::printAll(WINDOW* window, vector<int> nums, int start_y, int start_x){
	int offset;
	if(nums.size() < 6) offset = 12;
	else offset = 0;
	for(int i=0; i<nums.size(); i++){
		print(window, nums[i],  start_y, start_x+offset);
		offset += 12;
	}
}

vector<int> Digits::convert(float num){
	vector<int> nums;
	string n = to_string(num);
	int i=0;
	bool decimalEncountered = false;
	while(!decimalEncountered){
		if(n.at(i) == '.'){
			decimalEncountered = true;
			nums.push_back(10);
			i++;
		}
		nums.push_back(n.at(i)-'0');
		i++; 
	}
	//Read 2 digits after decimal point
	nums.push_back(n.at(i) -'0'); i++;
	nums.push_back(n.at(i) -'0');
	return nums;
/*
	//first digit
	nums.push_back(num / 10);
	//second digit
	nums.push_back(num % 10);
	//third digit
	nums.push_back((num % 1) / 10);
	//forth digit
	nums.push_back((num )*/
}
