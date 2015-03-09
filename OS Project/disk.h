//Aaron Settle
//2-5-15
//OS Project
#ifndef DISK_H
#define DISK_H
#include <array>
#include "PCB.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Disk
{
private:
	//change to public
	struct hardDisk
	{
		//Changed to new call and shorter length for current use and STDLIB method calls, if needed
		array<string, 2400> disk;
	};
	hardDisk testDisk;

	int startIndex, endIndex;
public:
	//Loads instructions into testDisk string array and creates a pcb instance with
	//values extracted from the Job and Data Control Cards
	void Disk::loader();

	//Prints testDisk's content
	void Disk::printDisk();
};
#endif 