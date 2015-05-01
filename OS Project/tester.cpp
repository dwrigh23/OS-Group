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
	/* THIS IS THE PSEUDO-CODE FOR OUR DRIVER 

			1. CALL LOADER TO LOAD EVERYTHING INTO DISK AND CREATE PCB VECTOR
			2. CALL LTS TO SORT PCB VECTOR IF PRIORITY SCHEDULING, ELSE PCB VECTOR IS FIFO 
			3. CALL LTS TO LOAD FIRST 15 PROCESSES INTO RAM BASED ON SORTING ORDER (FIFO, PRIORITY)
			4. CALL DISPATCHER TO SELECT PROCESSES FROM RAM (THEY ARE IN ORDER OF SELECTION)
			5. DISPATCHER CALLS LOADCPU METHOD PER PROCESS TO ALLOCATE IT A CPU FOR EXECUTION
			6. CALL FREERAM TO CLEAR RAM AFTER ALL 15 PROCESSES HAVE RUN
			7. REPEAT 3-5 UNTIL ALL JOBS ARE PROCESSED
			8. RECORD TIMING INFORMATION AT SOME UNDETERMINED POINT YET
			9. TERMINATE PROGRAM ONCE ALL 30 ARE FINISHED
		
	*/
	pcbtest.pcbVec2.pop_back();

	Sort.prioritySort(pcbtest.pcbVec2, 0, 29);

	testRam.resetRam();
	cpu1.resetRegisters();

	//Load Processes 0-13
	for (int i = 0; i < 14; i++){
		if (i == 0){
			Sort.ReadyQ[i].startRam = testRam.currentIndex;
			Sort.sendtoRam(Sort.ReadyQ[i]);
			Sort.ReadyQ[i].endRam = testRam.currentIndex - 1;
		}
		else{
			Sort.ReadyQ[i].startRam = testRam.currentIndex;
			Sort.sendtoRam(Sort.ReadyQ[i]);
			Sort.ReadyQ[i].endRam = testRam.currentIndex - 1;
		}
		cout << "Process: " << i << " startRam is: " << Sort.ReadyQ[i].startRam << endl;
		cout << "Process: " << i << " endRam is: " << Sort.ReadyQ[i].endRam << endl;
	}
	
	//Execute Processes 0-13
	for (int i = 0; i < 14; i++){
		cout << "Executing process #" << i << endl;
		 dispatch.passJob(Sort.ReadyQ[i], cpu1);
	}

	//Clear Processes 0-13
	testRam.resetRam();

	//Load Processes 14-28
	for (int i = 14; i < 28; i++){
		if (i == 14){
			Sort.ReadyQ[i].startRam = testRam.currentIndex;
			Sort.sendtoRam(Sort.ReadyQ[i]);
			Sort.ReadyQ[i].endRam = testRam.currentIndex - 1;
		}
		else{
			Sort.ReadyQ[i].startRam = testRam.currentIndex;
			Sort.sendtoRam(Sort.ReadyQ[i]);
			Sort.ReadyQ[i].endRam = testRam.currentIndex - 1;
		}
		cout << "Process: " << i << " startRam is: " << Sort.ReadyQ[i].startRam << endl;
		cout << "Process: " << i << " endRam is: " << Sort.ReadyQ[i].endRam << endl;
	}

	
	//Execute Processes 14-28
	for (int i = 14; i < 28; i++){
		cout << "Executing process #" << i << endl;
		dispatch.passJob(Sort.ReadyQ[i], cpu1);
	}


	system("pause");
}