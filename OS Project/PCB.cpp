#include "PCB.h"

using namespace std;

double elapsedTime(chrono::high_resolution_clock::time_point startTime, chrono::high_resolution_clock::time_point endTime){
	chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(endTime - startTime);
	return time_span.count();
};


void PCB::createPCB(int jobID, int codeSize, int priority, int startDisk, int endDisk){
	PCB pcb;

	pcb.jobID = jobID;
	pcb.codeSize = codeSize;
	pcb.priority = priority;
	pcb.startDisk = startDisk;
	pcb.endDisk = endDisk;
	pcb.programCounter = 0;
	pcb.processState = pcb.created;

	pcbVec.push_back(pcb);
};