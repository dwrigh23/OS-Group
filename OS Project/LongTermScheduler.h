#ifndef LONGETERMSCHEDULER_H
#define LONGTERMSCHEDULER_H
#include "PCB.h"
#include "RAM.h"
#include <vector>

class LongTermScheduler
{
public:
	//vector<PCB> vectorPartition(vector<PCB> PCBVector, int left, int right);

	void fifoSort(vector<PCB>& TempReadyQ, int left, int right);

	void prioritySort(vector<PCB>& TempReadyQ, int left, int right);

	void sjfSort(vector<PCB>& TempReadyQ, int left, int right);

	void printReadyQ();

	void sendToRam(vector<string> &instructionList, PCB currentProc);
}; 
extern LongTermScheduler Sort;
#endif