//this is the haeder file for the scheduler

#include<iostream.h>
#include<conio.h>
#include<stdio.h>

calss scheduler
{
  
  
  public 
  //First come first serve
  void fcfs();
  
  //Shortest job first
  void sjf();
  
  //Shortest job first with preemption
  void sjfp();
  
  //Shortest job first with nonpreemtion
  void sjfnp();
  
  //Round Robin
  void rr();
  
  //Priority
  void priority();
  
  //Get the data
  void getdata();
  
};
