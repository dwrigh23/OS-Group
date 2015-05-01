#include "PCB.h"

using namespace std;

PCB pcbtest;

double PCB::elapsedTime(chrono::high_resolution_clock::time_point startTime, chrono::high_resolution_clock::time_point endTime){
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

	pcbtest.pcbVec2.push_back(pcb);
};

void PCB::printPCB(){
	for (int i = 0; i <= 29; ++i){
		cout << "pcbVec[" << i << "] :  jobID: " << pcbVec2[i].jobID << endl;
		cout << "              codeSize: " << pcbVec2[i].codeSize << endl;
		cout << "              priority: " << pcbVec2[i].priority << endl;
		cout << endl;
	}
	cout << "PCB Printed." << std::endl;
};