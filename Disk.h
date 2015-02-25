//Aaron Settle
//2-24-15
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

	void Disk::loader();

	void Disk::print();
};
#endif 
