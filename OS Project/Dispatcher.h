#ifndef DISPATCHER_H
#include <string>
#include <iostream>
#include "Dispatcher.h"
#include "RAM.h"
#include "PCB.h"

//job variables
 int jobID = pcb.jobID;
int codeSize = pcb.codeSize;
int priority = pcb.priority;
int startDisk = pcb.startDisk;
int endDisk = pcb.endDisk;
int currentindex;

Void PassJob(Vector<> Jobs) // pass it The Job list
{};
	
	//Dont think this is necasary for the header file
	//header should only have declaration I beleive
/*
	if (RAM.getSpaceRemaining()) // Asks if there is space avaliable in the RAM
	{

	}
	else
	{
		break; // may be diffrent, but otherwise it waits to be called again and doesnt do anything unless space is avaliable.
	}*/

#endif
