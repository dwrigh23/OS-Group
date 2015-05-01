//Aaron Settle
//3-3-2015
//OS Project
#ifndef RAM_H 
#define RAM_H
#include "PCB.h"
#include <string>
#include <vector>
#include <array>

using namespace std;

class RAM {
private:

public:
	//As I have discovered through googling, only array instantiating in this form allows for STDLIB calls
	array<string, 1024> memory;

	int currentIndex = 0;

	//Erases contents of RAM (the memory array)
	void resetRam();

	//Erases elements through specified start and ending locations
	void freeRamLocation(int startIndex, int endIndex);

	//Populates the array
	void writeRam(vector<string> instruction, PCB pcb);

	//Populates the array from a specified start position
	void writeRamLocation(vector<string> instruction, PCB pcb, int startIndex);

	//Returns amount of unpopulated locations in RAM
	int getSpaceRemaining();

	//Returns percent of filled locations in RAM
	int getCurrentFillPercent();

	bool jobCanFit(PCB pcb);

	void printRam();
};
extern RAM testRam;

#endif