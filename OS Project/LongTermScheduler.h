#ifndef LONGETERMSCHEDULER_H
#define LONGTERMSCHEDULER_H
#include "PCB.h"
#include "RAM.h"
#include <vector>

class LongTermScheduler{
	
	vector<PCB> vectorPartition(vector<PCB> PCBVector, int left, int right);

	vector<PCB> prioritySort(vector<PCB> PCBVector, int left, int right);
	
	void SendtoRam(vector<PCB> PCBVector);
};

#endif
