#include <string>
#include <iostream>
#include "LongTermScheduler.h"

using namespace std;

void fifo(int JobID){ //First in first out
	for(int i = nextprocess; i <= pcb.pcbVec; i++;){ // just put all the processes into the ReadyQ to be passes off.
		ProcessQ[i] = pcb.pcbVec[i];
		ReadyQ[i]= ProcessQ[i];
	}
}

void Priority(int priority, int JobID){ //Priority
	for(int i = nextprocesss; i <= pcb.pcbVec; i++:){// put all process in the Process Q to be sorted
		ProcessQ[i] = pcb.pcbvect[i];
		int PQsize = ProcessQ.size();
	}
  
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
