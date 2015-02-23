//Aaron Settle
//2-5-15
//OS Project
#ifndef DISK_H
#define DISK_H
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Disk
{
private:
	struct hardDisk
	{
		string disk [4095];
		vector<int> pcbTemp;
	};
	hardDisk testDisk;

public:

	void Disk::get_data();

	void Disk::print();
};
#endif 
