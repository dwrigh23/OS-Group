//Aaron Settle
//2-5-15
//OS Project
#include "disk.h"

void Disk::get_data(){
	std::string line;
	int i = 0, id, codeSize, priority, inBuff, outBuff, tempBuff;
	std::ifstream input_file("Program-File.txt");
	if (!input_file)
	{
		// Print an error and exit
		std::cerr << "Cannot open file." << std::endl;
		exit(1);
	}

	while (input_file){
		std::getline(input_file, line);
		if (line.at(0) == '/'){
			if (line.at(3) == 'J'){
				line.erase(0, 6);
				std::istringstream iss(line);
				iss >> id >> std::hex >> codeSize >> priority;
				testDisk.pcbTemp.push_back(id);
				testDisk.pcbTemp.push_back(codeSize);
				testDisk.pcbTemp.push_back(priority);
			}
			else if (line.at(3) == 'D'){
				line.erase(0, 7);
				std::istringstream iss(line);
				iss >> std::hex >> inBuff >> std::hex >> outBuff >> std::hex >> tempBuff;
				testDisk.pcbTemp.push_back(inBuff);
				testDisk.pcbTemp.push_back(outBuff);
				testDisk.pcbTemp.push_back(tempBuff);
			}
			else if (line.at(3) == 'E'){
				line.erase();
			}
		}
		else
		{
			testDisk.disk[i] = line;
			i++;
		}
	}

	//Confirmation that get_data ran
	std::cout << "Data received." << std::endl;
}

void Disk::print(){
	for (string* p = &testDisk.disk[0]; p != &testDisk.disk[4095]; p++){
		cout << *p << endl;
	};
}
