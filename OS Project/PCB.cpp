#include "PCB.h"

void PCB::createPCB(int jobID, int codeSize, int priority, int startDisk, int endDisk){
	PCB pcb;

	jobID = pcb.jobID;
	codeSize = pcb.codeSize;
	priority = pcb.priority;
	startDisk = pcb.startDisk;
	endDisk = pcb.endDisk;

	pcb.programCounter = 0;
	pcb.processState = pcb.created;

	pcbVec.push_back(pcb);
};