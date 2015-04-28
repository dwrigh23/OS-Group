#include <string>
#include <iostream>
#include "LongTermScheduler.h"

using namespace std;

LongTermScheduler Sort;

vector<PCB> ReadyQ(30);

void LongTermScheduler::fifoSort(vector<PCB>& TempReadyQ, int left, int right){

	int i = left, j = right;
	//cout << i <<" "<< j << " <-- this is printed from the longterm inside prioritysort " << endl;
	PCB temp;
	//use the pivot as a middle point
	int pivot = TempReadyQ[(left + right) / 2].jobID;

	while (i <= j){ //partition smaller priority to the left of the pivot and larger priority to the right
		while (TempReadyQ[i].jobID < pivot)
			i++;
		while (TempReadyQ[j].jobID > pivot)
			j--;
		if (i <= j) {
			temp = TempReadyQ[i];
			TempReadyQ[i] = TempReadyQ[j];
			TempReadyQ[j] = temp;
			i++;
			j--;
		}

		//run through the array again recursively to double check that the priority number is in order
		if (left < j)
			fifoSort(TempReadyQ, left, j);
		if (i < right)
			fifoSort(TempReadyQ, i, right);
	}
	ReadyQ = TempReadyQ;

}

void LongTermScheduler::prioritySort(vector<PCB>& TempReadyQ, int left, int right){

	int i = left, j = right;
	//cout << i <<" "<< j << " <-- this is printed from the longterm inside prioritysort " << endl;
	PCB temp;
	//use the pivot as a middle point
	int pivot = TempReadyQ[(left + right) / 2].priority;

	while (i <= j){ //partition smaller priority to the left of the pivot and larger priority to the right
		while (TempReadyQ[i].priority < pivot)
			i++;
		while (TempReadyQ[j].priority > pivot)
			j--;
		if (i <= j) {
			temp = TempReadyQ[i];
			TempReadyQ[i] = TempReadyQ[j];
			TempReadyQ[j] = temp;
			i++;
			j--;
		}

		//run through the array again recursively to double check that the priority number is in order
		if (left < j)
			prioritySort(TempReadyQ, left, j);
		if (i < right)
			prioritySort(TempReadyQ, i, right);
	}

	ReadyQ = TempReadyQ;

}

void LongTermScheduler::sjfSort(vector<PCB>& TempReadyQ, int left, int right){

	int i = left, j = right;
	//cout << i <<" "<< j << " <-- this is printed from the longterm inside prioritysort " << endl;
	PCB temp;
	//use the pivot as a middle point
	int pivot = TempReadyQ[(left + right) / 2].codeSize;

	while (i <= j){ //partition smaller priority to the left of the pivot and larger priority to the right
		while (TempReadyQ[i].codeSize < pivot)
			i++;
		while (TempReadyQ[j].codeSize > pivot)
			j--;
		if (i <= j) {
			temp = TempReadyQ[i];
			TempReadyQ[i] = TempReadyQ[j];
			TempReadyQ[j] = temp;
			i++;
			j--;
		}

		//run through the array again recursively to double check that the priority number is in order
		if (left < j)
			sjfSort(TempReadyQ, left, j);
		if (i < right)
			sjfSort(TempReadyQ, i, right);
	}
	ReadyQ = TempReadyQ;
}

void LongTermScheduler::printReadyQ(){
	for (int i = 0; i <= 29; ++i){
		cout << "ReadyQ[" << i << "] :  jobID: " << ReadyQ[i].jobID << endl;
		cout << "              codeSize: " << ReadyQ[i].codeSize << endl;
		cout << "              priority: " << ReadyQ[i].priority << endl;
		cout << endl;
	}
}


void sendtoRam(vector<string> &instructionList, PCB currentProc){
	while (testRam.getSpaceRemaining() >= currentProc.codeSize)
	{
		int i = 0;
		testRam.RAM::writeRam(instructionList, currentProc);
		currentProc.startWaitTime = chrono::high_resolution_clock::now();
	}
}