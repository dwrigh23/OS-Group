#include "Dispatcher.h"

Dispatcher dispatch;

void Dispatcher::passJob(PCB currentProc, CPU cpuNum)
{
	cpuNum.loadCPU(currentProc);
};