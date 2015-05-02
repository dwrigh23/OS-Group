#include "CPU.h"
#include "disk.h"
#include "Dispatcher.h"
#include "LongTermScheduler.h"
#include "PCB.h"
#include "RAM.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(){


	
	CPU cpu1;

	testDisk.loader();

	//cout << "CHOOSE SORTING METHOD: ENTER P FOR PRIORITY, ENTER F FOR FIFO!" << endl;

	//Bandaid on pcbVec because it looks job 30 twice
	pcbtest.pcbVec2.pop_back();

	Sort.prioritySort(pcbtest.pcbVec2, 0, 29);

	testRam.resetRam();
	cpu1.resetRegisters();

	//Load Processes 0-14
	for (int i = 0; i < 15; i++){
			Sort.ReadyQ[i].startRam = testRam.currentIndex;
			Sort.sendtoRam(Sort.ReadyQ[i]);
			Sort.ReadyQ[i].endRam = testRam.currentIndex - 1;
		cout << "Process: " << i << " startRam is: " << Sort.ReadyQ[i].startRam << endl;
		cout << "Process: " << i << " endRam is: " << Sort.ReadyQ[i].endRam << endl;
	}
	
	//Execute Processes 0-14
	for (int i = 0; i < 15; i++){
		cout << "Executing process #" << i << endl;
		 dispatch.passJob(Sort.ReadyQ[i], cpu1);
	}

	//Clear Processes 0-14
	testRam.resetRam();

	//Load Processes 15-29
	for (int i = 15; i < 30; i++){
			Sort.ReadyQ[i].startRam = testRam.currentIndex;
			Sort.sendtoRam(Sort.ReadyQ[i]);
			Sort.ReadyQ[i].endRam = testRam.currentIndex - 1;
		cout << "Process: " << i << " startRam is: " << Sort.ReadyQ[i].startRam << endl;
		cout << "Process: " << i << " endRam is: " << Sort.ReadyQ[i].endRam << endl;
	}

	//Execute Processes 15-29
	for (int i = 15; i < 30; i++){
		cout << "Executing process #" << i << endl;
		dispatch.passJob(Sort.ReadyQ[i], cpu1);
	}
	system("pause");
}