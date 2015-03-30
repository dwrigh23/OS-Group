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
	//Storage unit for PCB instances of jobs, better than linked list b/c lower overhead and simple to use
	vector<PCB> pcbVec;

	//Job properties
	int jobID, codeSize, priority, inBuffer, outBuffer, tempBuffer, programCounter;

	//Job location indexes
	int startDisk, endDisk, startRam, endRam;

	//Data Properties
	int dataStartDisk, dataEndDisk, dataStartRam, dataEndRam;

	//Reserved process states
	enum processStatus { 
		error, 
		created, 
		ready, 
		waiting, 
		running, 
		terminated };

	//Called for PCB use
	processStatus processState;

	void createPCB(int jobID, int codeSize, int priority, int startDisk, int endDisk, int dataStartDisk, int dataEndDisk);

	int dataSize(int dataStartDisk, int dataEndDisk);
};
PCB pcb;
#endif