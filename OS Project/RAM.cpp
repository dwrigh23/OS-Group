//Aaron Settle
//3-3-2015
//OS Project
#include "RAM.h"
#include "PCB.h"
#include <string>
#include <array>
#include <iostream>


int RAM::getSpaceRemaining(){
	return testRam.maxFill - testRam.currentFill; //Max possible fill - current element count
}

int RAM::getCurrentFill(){
	return testRam.currentFill / 1024;	//current element count
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

void RAM::writeRam(vector<string> instructions){
	int i = 0, counter = 0;
	while (instructions[i] != ""){
		if (counter == 0){
			pcb.startRam = currentIndex;
		}
		else{
			if (testRam.currentIndex < testRam.maxFill && testRam.currentIndex > -1)
			{
				if (testRam.memory[currentIndex] == ""){
					testRam.memory[currentIndex] = instructions[i];
					currentIndex++, i++, counter++;
				}
				//need to track start/end pos
				else{
					while (testRam.memory[currentIndex] != ""){
						currentIndex++;
					}
				}
			}
			else{
				cout << "Write failed. RAM is full or index is out of range." << endl;
			}
		}
	}
	pcb.endRam = currentIndex;
}

void RAM::writeRamLocation(vector<string> instructions, int startIndex){
	currentIndex = startIndex;
	int i = 0, counter = 0;
	while (instructions[i] != ""){
		if (counter == 0){
			pcb.startRam = currentIndex;
		}

		if (startIndex > -1 && startIndex < testRam.maxFill){
			if (testRam.memory[currentIndex] == ""){
				testRam.memory[currentIndex] = instructions[i];
				currentIndex++, i++, counter++;
			}
			//need to track start/end pos
			else{
				while (testRam.memory[currentIndex] != ""){
					currentIndex++;
				}
			}
		}
		else{
			cout << "Invalid instruction or memory location." << endl;
		}
	}
	pcb.endRam = currentIndex;
};