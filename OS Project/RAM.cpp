//Aaron Settle
//3-3-2015
//OS Project
#include "RAM.h"
#include "PCB.h"
#include <string>
#include <array>
#include <iostream>

RAM testRam;

int RAM::getSpaceRemaining(){	//Max possible fill - current element count
	int diff = testRam.memory.max_size() - testRam.memory.size();
	if (diff > 0){
		return diff;
	}
	if (diff = 0){
		cout << "RAM is full!" << endl;
	}
}

int RAM::getCurrentFillPercent(){
	return testRam.memory.size() / 1024;	//Returns percent of filled locations in RAM
}

void RAM::resetRam(){
	//Loops through every element and replaces its contents with an empty string
	for (int i = 0; i < testRam.memory.max_size() ; i++){
		testRam.memory[i] = "";
	}
};

void RAM::freeRamLocation(int startIndex, int endIndex){
	//Loops through every element in a specified range and replaces its content with an empty string
	for (int i = startIndex; i < endIndex; i++){
		testRam.memory[i] = "";
	}
};

bool RAM::jobCanFit(PCB pcb){
	if (testRam.getSpaceRemaining() - (currentIndex + (pcb.endDisk - pcb.startDisk)) >= 0){
		return true;
	}
	else{
		return false;
	}
};

void RAM::writeRam(vector<string> instructions, PCB pcb){
	int i = 0, counter = 0;
	while(instructions[i] != "" && testRam.memory[currentIndex] == ""){
		if (counter == 0){
			pcb.startRam = currentIndex;
			//pcb.dataStartRam = pcb.startRam + (pcb.codeSize + 1);
			counter++;
		}
		
		if (testRam.currentIndex <= testRam.memory.max_size() && testRam.currentIndex > -1)
		{
			if (testRam.memory[currentIndex] == ""){
				testRam.memory[currentIndex] = instructions[i];
				currentIndex++, i++;
			}
			/*else{
				while (testRam.memory[currentIndex] != ""){
					currentIndex++;
				}
				*/
			else{
				cout << "Write failed. RAM is full or index is out of range." << endl;
			}
		}
		}
	pcb.endRam = currentIndex;
	//pcb.dataEndRam = currentIndex;
};

void RAM::writeRamLocation(vector<string> instructions, PCB pcb, int startIndex){
	currentIndex = startIndex;
	int i = 0, counter = 0;
	while (instructions[i] != ""){
		if (counter == 0){
			pcb.startRam = currentIndex;
			pcb.dataStartRam = pcb.startRam + (pcb.codeSize + 1);
		}

		if (startIndex > -1 && startIndex < testRam.memory.max_size()){
			if (testRam.memory[currentIndex] == ""){
				testRam.memory[currentIndex] = instructions[i];
				currentIndex++, i++, counter++;
			}
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
	pcb.dataEndRam = currentIndex;
};