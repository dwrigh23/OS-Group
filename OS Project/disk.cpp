//Aaron Settle
//2-24-15
//OS Project
#include "disk.h"

Disk testDisk;

void Disk::loader(){
	std::string line;
	//Temp Variable
	int i = 0;

	//Attribute variables
	int id, codeSize, priority, inBuff, outBuff, tempBuff, startIndex, endIndex, dataStartDisk, dataEndDisk;

	//File containing instructions and control cards
	std::ifstream input_file("Program-File.txt");

	if (!input_file)
	{
		// Print an error and exit
		std::cerr << "Cannot open file." << std::endl;
		exit(1);
	}

	while (input_file){
		//Retrieve instructions
		std::getline(input_file, line);

		//Analyze line to determine if it's a Job, Data, or End control card
		if (line.at(0) == '/'){
			if (line.at(3) == 'J'){
				line.erase(0, 6);
				std::istringstream iss(line);
				iss >> id >> std::hex >> codeSize >> priority;	//Extract JCC values
				startIndex = i;
			}
			else if (line.at(3) == 'D'){
				line.erase(0, 7);
				std::istringstream iss(line);
				iss >> std::hex >> inBuff >> std::hex >> outBuff >> std::hex >> tempBuff; //Extract DCC values
				dataStartDisk = i;
			}
			else if (line.at(3) == 'E'){
				endIndex = i;
				dataEndDisk = i;
				PCB().createPCB(id, codeSize, priority, startIndex, endIndex);
			}
		}
		else
		{
			testDisk.disk[i] = line;	//Store instruction and increment counter
			i++;
		}
	}

	//Confirmation that loader ran
	std::cout << "Data received." << std::endl;
}

void Disk::printDisk(){
	for (int i = 0; i < 2200; i++){
		cout << testDisk.disk[i] << endl;
	}
}