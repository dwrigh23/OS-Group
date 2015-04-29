#include "disk.h"
#include "RAM.h"
#include "PCB.h"
#include "LongTermScheduler.h"
#include "CPU.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(){
	CPU cpu;

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

	//vector<PCB> testpcbVec;
	pcbtest.printPCB();

	cout << endl;
	cout << "--------Sorting by Priority--------" << endl;
	system("pause");
	Sort.prioritySort(pcbtest.pcbVec2, 0, 29);
	pcbtest.printPCB();

	cout << endl;
	cout << "-------------- Printing from the ReadyQ inside the long term scheduler------------" << endl;
	system("pause");
	Sort.printReadyQ();
	cout << endl;
	
	//writing first 15 to RAM
	for (int i = 0; i < 15; i++){
		//Fetch instructions to write for job
		//CPU().fetch(ReadyQ[i]);
		//Write job's instructions to RAM and pass current PCB too for variable saving
		//Sort.sendToRam(tempVector, ReadyQ[i]);
	}

	

	system("pause");
}