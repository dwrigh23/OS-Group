//Aaron Settle
//2-5-15
//OS Project
#ifndef DISK_H
#define DISK_H
#include <vector>
#include "PCB.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Disk
{
private:
	struct hardDisk
	{
		string disk [4096];
	};
	hardDisk testDisk;

	int startIndex, endIndex;
public:
	//Loads instructions into testDisk string array and creates a pcb instance with
	//values extracted from the Job and Data Control Cards
	void Disk::loader();

	//Prints testDisk's content
	void Disk::print();
};
#endif 
