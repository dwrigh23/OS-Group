#include "Dispatcher.h"


#include <string>
#include <iostream>
#include "Dispatcher.h"
#include "RAM.h"
#include "PCB.h"

// variables for it to extract the perameters from the PCB into
int jobID = pcb.jobID;
int codeSize = pcb.codeSize;
int priority = pcb.priority;
int startDisk = pcb.startDisk;
int endDisk = pcb.endDisk;
int currentindex;

Void PassJob(Vector<> Jobs)
{
	currentindex = 0;   // use this to remember what index it is at, for when we do context switching or cant pass job to RAM
	
	if (RAM.getSpaceRemaining())   // Asks if there is space avaliable in the RAM
	{
		//These are the dispatcher extracting the job parameters from the pcb , only does this if space is avaliable in RAM
		
		jobID = PCB.pcbVec[currentindex].JobID;
		codeSize = PCB.pcbVec[currentindex].codesize;
		priority = PCB.pcbVec[currentindex].priority;
		startdisk = PCB.pcbVec[currentindex].startdisk;
		enddisk = PCB.pcbVec[currentindex].enddisk;

		//somehow pass this to the CPU
		CPU::fetch(PCB currentProc);



		currentindex++;   // use this to remember what index it is at, for when we do context switching or cant pass job to RAM
		
	}
	else
	{
		break;   // may be diffrent, but otherwise it waits to be called again and doesnt do anything unless space is avaliable.
	}
}
