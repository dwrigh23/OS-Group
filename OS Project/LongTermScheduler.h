#ifndef LONGETERMSCHEDULER_H
#define LONGTERMSCHEDULER_H
#include "PCB.h"
#include "disk.h"
#include "RAM.h"
//#include "RAM.h"
#include <vector>

class LongTermScheduler
{
public:

	vector<PCB> ReadyQ;

	vector<string> getInstructions(PCB currentProc);

	void fifoSort(vector<PCB>& TempReadyQ, int left, int right);

	void prioritySort(vector<PCB>& TempReadyQ, int left, int right);

	void sjfSort(vector<PCB>& TempReadyQ, int left, int right);

	void printReadyQ();

	void sendtoRam(PCB currentProc);
};
extern LongTermScheduler Sort;

#endif