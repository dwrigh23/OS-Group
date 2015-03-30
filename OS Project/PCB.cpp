//Aaron Settle
//2-24-2015
//OS Project
#include "PCB.h"

void PCB::createPCB(int jobID, int codeSize, int priority, int startDisk, int endDisk, int dataStartDisk, int dataEndDisk){
	PCB pcb;

	jobID = pcb.jobID;
	codeSize = pcb.codeSize;
	priority = pcb.priority;
	startDisk = pcb.startDisk;
	endDisk = pcb.endDisk;
	dataStartDisk = pcb.dataStartDisk;
	dataEndDisk = pcb.dataEndDisk;

	pcb.programCounter = 0;
	pcb.processState = pcb.created;

	pcb.pcbVec.push_back(pcb);
};

int dataSize(int dataStartDisk, int dataEndDisk){
	return (dataEndDisk - dataStartDisk);
};
