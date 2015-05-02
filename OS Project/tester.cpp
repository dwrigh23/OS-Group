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


	ofstream timingData;
	timingData.open("TimingData.txt");

	CPU cpu1;
	char response;

	testDisk.loader();

	//Bandaid on pcbVec because it loads job 30 twice
	pcbtest.pcbVec2.pop_back();

	cout << "CHOOSE SORTING METHOD: ENTER P FOR PRIORITY SORT, F FOR FIFO SORT, S FOR SHORTEST JOB FIRST!" << endl;
	cin >> response;
	putchar(toupper(response));

	switch (response){
	case 'P':
		Sort.prioritySort(pcbtest.pcbVec2, 0, 29);
		break;
	case 'F':
		Sort.fifoSort(pcbtest.pcbVec2, 0, 29);
		break;
	case 'S':
		Sort.sjfSort(pcbtest.pcbVec2, 0, 29);
		break;
	default:break;
	}

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
		 //Print times here
		 timingData << "Elapsed Waiting Time Process: " << i << " is " << Sort.ReadyQ[i].elapsedTime(Sort.ReadyQ[i].startWaitTime, Sort.ReadyQ[i].endWaitTime) << endl;
		 timingData << "Elapsed Execute Time Process: " << i << " is " << Sort.ReadyQ[i].elapsedTime(Sort.ReadyQ[i].startExecuteTime, Sort.ReadyQ[i].endExecuteTime) << endl;
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
		//Print times here
		timingData << "Elapsed Waiting Time Process: " << i << " is " << Sort.ReadyQ[i].elapsedTime(Sort.ReadyQ[i].startWaitTime, Sort.ReadyQ[i].endWaitTime) << endl;
		timingData << "Elapsed Execute Time Process: " << i << " is " << Sort.ReadyQ[i].elapsedTime(Sort.ReadyQ[i].startExecuteTime, Sort.ReadyQ[i].endExecuteTime) << endl;
	}
	system("pause");
}