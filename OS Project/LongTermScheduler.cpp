#include <string>
#include <iostream>
#include "LongTermScheduler.h"

using namespace std;

LongTermScheduler Sort;

void LongTermScheduler::fifoSort(vector<PCB>& TempReadyQ, int left, int right){

	int i = left;
	int j = right;
	
	int pivot = ((left + right) / 2);

	while (i <= j){ //partition smaller priority to the left of the pivot and larger ID to the right
		while (TempReadyQ[i].jobID < TempReadyQ[pivot].jobID)
			i++;
		while (TempReadyQ[j].jobID > TempReadyQ[pivot].jobID)
			j--;
		if (i <= j) {
			swap(TempReadyQ[i], TempReadyQ[j]);
			i++;
			j--;
		}
	}
		//run through the array again recursively to double check that the ID number is in order
		if (left < j){
			fifoSort(TempReadyQ, left, j);
		}
		if (i < right){
			fifoSort(TempReadyQ, i, right);
		}
	
	Sort.ReadyQ = TempReadyQ;
}

void LongTermScheduler::prioritySort(vector<PCB>& TempReadyQ, int left, int right){

	int i = left;
	int j = right;

	int pivot = ((left + right) / 2);

	while (i <= j){ //partition smaller priority to the left of the pivot and larger priority to the right
		while (TempReadyQ[i].priority < TempReadyQ[pivot].priority)
			i++;
		while (TempReadyQ[j].priority > TempReadyQ[pivot].priority)
			j--;
		if (i <= j) {
			swap(TempReadyQ[i], TempReadyQ[j]);
			i++;
			j--;
		}
	}
		//run through the array again recursively to double check that the priority number is in order
		if (left < j){
			prioritySort(TempReadyQ, left, j);
		}
		if (i < right){
			prioritySort(TempReadyQ, i, right);
		}

	Sort.ReadyQ = TempReadyQ;
}

void LongTermScheduler::sjfSort(std::vector<PCB>& TempReadyQ, int left, int right)
{
	int i = left;
	int j = right;
	int pivot = ((left + right) / 2);

	while (i <= j){ //partition smaller priority to the left of the pivot and larger codeSize to the right
		while (TempReadyQ[i].codeSize < TempReadyQ[pivot].codeSize){
			i++;
		}
		while (TempReadyQ[j].codeSize > TempReadyQ[pivot].codeSize){
			j--;
		}
		if (i <= j){
			swap(TempReadyQ[i], TempReadyQ[j]);
			i++;
			j--;
		}
	}

	//run through the array again recursively to double check that the codeSize number is in order
	if (left < j){
		sjfSort(TempReadyQ, left, j);
	}
	if (i > right){
		sjfSort(TempReadyQ, i, right);
	}

	Sort.ReadyQ = TempReadyQ;
}

void LongTermScheduler::printReadyQ(){
	ofstream myfile2;
	myfile2.open("PrintOutReadyQFile.txt");

	for (int i = 0; i <= 29; ++i){
		cout << "ReadyQ[" << i << "] :  jobID: " << Sort.ReadyQ[i].jobID << endl;
		cout << "              codeSize: " << Sort.ReadyQ[i].codeSize << endl;
		cout << "              priority: " << Sort.ReadyQ[i].priority << endl;
		cout << endl;
		myfile2 << "ReadyQ[" << i << "] :  jobID: " << Sort.ReadyQ[i].jobID << endl;
		myfile2 << "              codeSize: " << Sort.ReadyQ[i].codeSize << endl;
		myfile2 << "              priority: " << Sort.ReadyQ[i].priority << endl;
		myfile2 << endl;
	}
	myfile2.close();
}

vector<string> LongTermScheduler::getInstructions(PCB currentProc){
	vector<string> diskFetch;
	string currentInstr;
	for (int i = currentProc.startDisk; i <= currentProc.endDisk; i++){
		currentInstr = testDisk.disk[i];
		diskFetch.push_back(currentInstr);
	}
	return diskFetch;
}

void LongTermScheduler::sendtoRam(PCB currentProc){ 
	if(testRam.getSpaceRemaining() >= currentProc.codeSize){
		testRam.writeRam(Sort.getInstructions(currentProc), currentProc);
		currentProc.startWaitTime = chrono::high_resolution_clock::now();
	}
}

