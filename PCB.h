//Aaron Settle
//2-24-2015
//OS Project
#ifndef PCB_H 
#define PCB_H  
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class PCB
{
public:
	vector<PCB> pcbVec;
	int jobID, codeSize, priority, inBuffer, outBuffer, tempBuffer, programCounter;
	int startDisk, endDisk, startRam, endRam;
};

#endif
