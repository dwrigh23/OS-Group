//this is the haeder file for the scheduler

#include<iostream.h>
#include<conio.h>
#include<stdio.h>

calss scheduler
{
  
  //the refrence i am looking at had these but idk if we really need them
  //http://cplusplus.happycodings.com/algorithms/code37.html
  
  //I think this is an array to hold user inputed burst times
 // int Bu[20];
 
 //No idea what any of this is.....
//float Twt,Awt,A[10],Wt[10],w;
  
  public 
  //First in first out
  void fifo();
  
  //Shortest job first
  void sjf();
  
  //Shortest job first with preemption
  void sjfp();
  
  //Shortest job first with nonpreemtion
  void sjfnp();
  
  //Round Robin
  void rr();
  
  //Get the data
  //NOt sure if this is necisary.....
  void getdata();
  
  
  bool CheckRam();
  
  void getJobAddress();
  
  int Priority();
  
};
