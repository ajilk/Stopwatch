#include "Stats.h"

Stats::Stats(){}

void Stats::add(float solve){
	solves.push_back(solve);
}

float Stats::getTotalSolves(){
	return solves.size();
}

float Stats::getAverage(){
	if(solves.size() <= 0) return 0;
	float totalTime;
	for(int i=0; i<solves.size(); i++){
		totalTime += solves.at(i);	
	}
	return totalTime/solves.size();
}

float Stats::getAverage10(){
	if(solves.size() < 10) return 0;
	float totalTime;
	int count = 0;
	for(int i=solves.size()-1; count<10; i--){
		totalTime += solves.at(i);
		count++;
	}
	return totalTime/10;
}

float Stats::getAverage5(){
	if(solves.size() < 5) return 0;
	float totalTime;
	int count = 0;
	for(int i=solves.size()-1; count<5; i--){
		totalTime += solves.at(i);
		count++;
	}
	return totalTime/5;
}

float Stats::getBest(){
	if(solves.empty()) return 0;
	return *std::min_element(solves.begin(), solves.end());
}

float Stats::getWorst(){
	if(solves.empty()) return 0;
	return *std::max_element(solves.begin(), solves.end());
}

void Stats::reset(){
	solves.clear();
}

void Stats::print(WINDOW* window, int start_y, int start_x){
	if(solves.size() > 30){
		for(int i=solves.size()-30; i<solves.size(); i++){
			mvwprintw(window, start_y+(i-(solves.size()-30)), start_x, "%d:\t--\t%.3f", i+1, solves.at(i));
		}
	}
	else{
		for(int i=0; i<solves.size(); i++){
			mvwprintw(window, start_y+i, start_x, "%d:\t--\t%.3f", i+1, solves.at(i));
		}
	}
	mvwprintw(window, start_y+31, start_x, "Average:\t%.3f", getAverage());	
	mvwprintw(window, start_y+32, start_x, "Average of 10:\t%.3f", getAverage10());
	mvwprintw(window, start_y+33, start_x, "Average of 5:\t%.3f", getAverage5());
	mvwprintw(window, start_y+34, start_x, "Best:\t\t%.3f", getBest());
	mvwprintw(window, start_y+35, start_x, "Worst:\t\t%.3f", getWorst());

}

