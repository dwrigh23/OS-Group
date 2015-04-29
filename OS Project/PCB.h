//Aaron Settle
//2-24-2015
//OS Project
#ifndef PCB_H 
#define PCB_H  
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>

using namespace std;
class PCB
{
public:
	//Storage unit for PCB instances of jobs, better than linked list b/c lower overhead and simple to use
	vector<PCB> pcbVec2;

	//Job properties
	int jobID, codeSize, priority, inBuffer, outBuffer, tempBuffer, programCounter;

	//Job location indexes
	int startDisk, endDisk, startRam, endRam;

	//Data Properties
	int dataStartDisk, dataEndDisk, dataStartRam, dataEndRam;

	//Timer variables
	chrono::high_resolution_clock::time_point startExecuteTime, startWaitTime, endExecuteTime, endWaitTime;

	//Reserved process states
	enum processStatus {
		error,
		created,
		ready,
		waiting,
		running,
		terminated
	};

	//Called for PCB use
	processStatus processState;

	double elapsedTime(chrono::high_resolution_clock::time_point startTime, chrono::high_resolution_clock::time_point endTime);

	void createPCB(int jobID, int codeSize, int priority, int startDisk, int endDisk);

	void printPCB();

};
extern PCB pcbtest;
#endif