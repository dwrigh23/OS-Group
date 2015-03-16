//Aaron Settle
//3-3-2015
//OS Project
#include "RAM.h"
#include <string>
#include <array>
#include <iostream>


int RAM::getSpaceRemaining(){
	return testRam.maxFill - testRam.currentFill; //Max possible fill - current element count
}

int RAM::getCurrentFill(){
	return testRam.currentFill;	//current element count
}

void RAM::resetRam(){
	//Loops through every element and replaces its contents with an empty string
	for (int i = 0; i < testRam.maxFill ; i++){
		testRam.memory[i] = "";
	}
};

void RAM::freeRamLocation(int startIndex, int endIndex){
	//Loops through every element in a specified range and replaces its content with an empty string
	for (int i = startIndex; i < endIndex; i++){
		testRam.memory[i] = "";
	}
};

void RAM::writeRam(string instruction){
	if (instruction != "")
	{
		if (testRam.currentIndex < testRam.maxFill && testRam.currentIndex > -1)
		{
			testRam.memory[currentIndex] = instruction;
			currentIndex++;
			//need to track start/end pos
		};
	}
	else
	{
		cout << "Instruction is NULL/Empty!" << endl;
	};
}

void RAM::writeRamLocation(string instruction, int startIndex){
	currentIndex = startIndex;
	if (instruction != "" && startIndex > -1 && startIndex < testRam.maxFill)
	{
		testRam.memory[startIndex] = instruction;
		//need to track start/end pos
	}
	else
	{
		cout << "Invalid instruction or memory location." << endl;
	}
};