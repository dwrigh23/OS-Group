#include <string>
#include <iostream>
#include "LongTermScheduler.h"

using namespace std;

vector<PCB> LongTermScheduler::vectorPartition(vector<PCB> PCBVector, int left, int right)
{
	int pivot = PCBVector[left].priority;
	int i = left;
	
	for(int j = left + 1; i < PCBVector.size(); j++)
	{
		if (PCBVector[j].priority <= pivot)
		{
			i = i + 1;
			swap(PCBVector[i], PCBVector[j]);
		}
	}
	swap(PCBVector[i], PCBVector[left]);
}

vector<PCB> LongTermScheduler::prioritySort(vector<PCB> PCBVector, int left, int right)
{
	int left = 0;
	int right = PCBVector.size();
	
	if(left < right)
	{
		vector<PCB> vector = vectorPartition(PCBVector, left, right);
		
		prioritySort(PCBVector, left, vector.max_size());
		prioritySort(PCBVector, left + 1, right);
	}
}

void SendtoRam(vector<PCB> PCBVector)
{
	while(testRam.getSpaceRemaining() != 1024)
	{
		PCBVector.writeRam(); 
	}
}

//################################################################################################
//################################################################################################
//################################################################################################
//################################################################################################
/*

///Old code that we dont think we need but do not want to get ridd ofjust yet

void fifo(int JobID){ //First in first out          ******is passing the JobID correct???***** pcbVec.size()
	for(int i = nextprocess; i <= 30; i++;){ // just put all the processes into the ReadyQ to be passes off.
		ProcessQ[i] = pcb.pcbVec[i];       //****** will i=nextprocess work???********
		ReadyQ[i]= ProcessQ[i];
	}
}

void Priority(int priority, int JobID){ //Priority
	for(int i = nextprocesss; i <= pcb.pcbVec; i++:){// put all process in the Process Q to be sorted
		ProcessQ[i] = pcb.pcbvect[i];
		int PQsize = ProcessQ.size();      //does this need to be inside the for loop???
	} ///nested for loop????
  
	for(int i = 0; i<= PQsize;i++){ //attempt to sort the processes based on its priority this may be backwards
		for (int j = 1; j <= PQsize;j++){
			int temprocessID;
			if(ProcessQ[i].priority > ProcessQ[j].priority){ //sorting the vectors, still may be backwards
				temprocess = ProcessQ[i];
				ProcessQ[i] = ProcessQ[j];
				ProcessQ[j] = temprocess;
				}
		} 
	 }
}
*/
