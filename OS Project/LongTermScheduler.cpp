
#include <string>
#include <iostream>
#include "Scheduler.h"

using namespace std

Vector<> ProcessQ;
Vector<> ReadyQ;
int nextprocess=0;

void scheduler::getdata(){
}

void fifo(int JobID){ //First in first out
  for(int i = nextprocess; i<=PCB.pcbvect; i++;) // just put all the processes into the ReadyQ to be passes off.
  {
    ProcessQ[i] = PCB.pcbvect[i];
    ReadyQ[i]= ProcessQ[i];
  }
}

void Priority(int priority, int JobID){ //Priority
  for(int i= nextprocesss; i<= PCB.pcbvect; i++:)// put all process in the Process Q to be sorted
  {
    ProcessQ[i]= PCB.pcbvect[i];
    int PQsize=ProcessQ.size();
  }
  
  for(int i = 0; i<= PQsize;i++) //attempt to sort the processes based on its priority this may be backwards
  {
    for (int j=1; j<=PQsize;j++)
    {
      int temprocessID;
      if(ProcessQ[i].priority>ProcessQ[j].priority) //sorting the vectors, still may be backwards
      {
       temprocess=ProcessQ[i];
       ProcessQ[i]=ProcessQ[j];
       ProcessQ[j]=temprocess;
      }
    } 
  }
}
