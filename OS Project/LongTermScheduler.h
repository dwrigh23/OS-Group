#ifndef LONGETERMSCHEDULER_H
#define LONGTERMSCHEDULER_H
#include "PCB.h"
#include "RAM.h"
#include <vector>

class LongTermScheduler{
	
	void vectorPartition(vector<PCB> PCBVector, int left, int right);

	void priorityFifoSort(vector<PCB> PCBVector);
	
	void SendtoRam(vector<PCB> PCBVector);
};

#endif
