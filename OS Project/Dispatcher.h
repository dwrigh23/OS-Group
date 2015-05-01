#ifndef DISPATCHER_H
#define DISPATCHER_H
#include "RAM.h"
#include "PCB.h"
#include "CPU.h"
#include <string>
#include <iostream>

using namespace std;

class Dispatcher{

public:
	void passJob(PCB currentProc, CPU cpuNum);

};
extern Dispatcher dispatch;
#endif