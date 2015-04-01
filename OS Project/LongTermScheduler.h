#ifndef LONGETERMSCHEDULER_H
#define LONGTERMSCHEDULER_H
#include "PCB.h"
#include <vector>

class LongTermScheduler{
	vector<PCB> ProcessQ;
	vector<PCB> ReadyQ;
	int nextprocess = 0;

	void fifo(int jobID);

	void priority(int priority, int jobID);
};


#endif