//Aaron Settle
//2-28-2015
//OS Project
#include "CPU.h"
#include <bitset>
#include <string>
#include <iostream>
#include <sstream>
#include <chrono>

vector<string> CPU::fetch(PCB currentProc){
	//-get current instance of pcb from ready queue(vector)
	string currentInstr;
	vector<string> instrList;

		//- for (use pcb's ram start location as initial location)
	//{
		//-copy instruction from ram location to a vector or array
			//- increment PC
			//- iterate thru ram until it reaches pcb's ram end location/reaches pcb.codesize
	//}
	for (int i = currentProc.startRam; i <= currentProc.endRam; i++){
		currentInstr = testRam.memory[i];
		instrList.push_back(currentInstr);
	}

	//-return the list of instructions
	return instrList;
};

vector<string> CPU::decode(vector<string> &instrList){
	string binary;
	vector<string> decodedInstr;
	for (int i = 0; i <= instrList.size(); i++){
		instrList[i].erase(0, 2);
		for (int j = 0; j != instrList[i].length(); ++j){
			binary += hexSwitch(instrList[i].at(j));
		}
		decodedInstr.push_back(binary);
	}
	return decodedInstr;
};

const char* CPU::hexSwitch(char hex){
	switch (hex)
	{
	case '0': return "0000";
	case '1': return "0001";
	case '2': return "0010";
	case '3': return "0011";
	case '4': return "0100";
	case '5': return "0101";
	case '6': return "0110";
	case '7': return "0111";
	case '8': return "1000";
	case '9': return "1001";
	case 'A': return "1010";
	case 'B': return "1011";
	case 'C': return "1100";
	case 'D': return "1101";
	case 'E': return "1110";
	case 'F': return "1111";
	}
};

void CPU::execute(string binary, PCB &currentProc){
		string caseBits = binary.substr(0, 2);

		//Case 1: If substring == "00"
		//Arithmetic instruction format
		if (caseBits == "00"){
			arithmeticFormat(binary);
		};

		//Case 2: If substring == "01"
		//Condition branch and immediate format
		if (caseBits == "01"){
			branchFormat(binary, currentProc.programCounter);
		}
		//Case 3: If substring == "10"
		//Conditional jump format
		if (caseBits == "10"){
			jumpFormat(binary, currentProc.programCounter);
		}
		//Case 4: If substring == "11"
		//IO instruction format
		if (caseBits == "11"){
			ioFormat(binary, currentProc);
		}
}

//Case 00, register transfer using 2 sources and 1 destination
//so this uses the "R" type instructions of: MOV ADD SUB MUL DIV AND OR SLT
void CPU::arithmeticFormat(string binary){
	//convert opcode into integral type for switch
	bitset<6> oc(binary.substr(2, 6));
	int opcode = oc.to_ulong();

	//convert binary substrings to decimal integers for accessing registers by index properly
	int src_reg = stoi(binary.substr(8, 4), nullptr, 2);
	int src_reg2 = stoi(binary.substr(12, 4), nullptr, 2);
	int dest_reg = stoi(binary.substr(16, 4), nullptr, 2);
	int temp;

	//using switch for opcode as suggested in specs
	switch (opcode){
	case 000100:  //000100(2) = 04(16), Instruction: MOV
		registers[src_reg] = registers[src_reg2];
		break;
	case 000101:  //000101(2) = 05(16), Instruction: ADD
		registers[dest_reg] = registers[src_reg] + registers[src_reg2];
		break;
	case 000110:  //000110(2) = 06(16), Instruction: SUB
		registers[dest_reg] = registers[src_reg] - registers[src_reg2];
		break;
	case 000111:  //000111(2) = 07(16), Instruction: MUL
		registers[dest_reg] = registers[src_reg] * registers[src_reg2];
		break;
	case 001000:  //001000(2) = 08(16), Instruction: DIV
		if (src_reg2 == 0){
			cout << "Cannot divide by 0";
			return;
		}
		else{
			registers[dest_reg] = registers[src_reg] / registers[src_reg2];
		}
		break;
	case 001001:  //001001(2) = 09(16), Instruction: AND
		temp = src_reg & src_reg2;
		registers[dest_reg] = temp;
		break;
	case 001010:  //001010(2) = 0A(16), Instruction: OR
		temp = src_reg | src_reg2;
		registers[dest_reg] = temp;
		break;
	case 010000:  //010000(2) = 10(16), Instruction: SLT
		if (registers[src_reg] < registers[src_reg2]){
			registers[dest_reg] = 1;
		}
		else{
			registers[dest_reg] = 0;
		}
		break;
	
	default: break;
	}
};

//Case 01, Conditional Brance and Immediate format using "I" type instructions:
//ST LW MOVI ADDI MULI DIVI LDI SLTI BEQ BNE BEZ BNZ BGS BLZ
void CPU::branchFormat(string binary, int &programCounter){
	//convert opcode into integral type for switch
	bitset<6> oc(binary.substr(2, 6));
	int opcode = oc.to_ulong();

	//convert binary substrings to decimal integers for accessing registers by index properly
	int b_reg = stoi(binary.substr(8, 4), nullptr, 2);
	int d_reg = stoi(binary.substr(12, 4), nullptr, 2);
	int address = stoi(binary.substr(16, 16), nullptr, 2); //For Branch, it is divided by 4 because, in byte addressing, a word uses 4 bytes.
			//Therefore, using word alignment, we can only access addresses that are divisible by 4.
	switch (opcode)
	{
	case 001011:  // 001011(2) = 0B(16), Instruction: MOVI
		registers[d_reg] = address;
		break;
	case 001100:  //001100(2) = 0C(16), Instruction: ADDI
		registers[d_reg] = registers[b_reg] + address;
		break;
	case 001101:  //001101(2) = 0D(16), Instruction: MULI
		registers[d_reg] += b_reg * (address);
		break;
	case 001110:  //001110(2) = 0E(16), Instruction: DIVI
		registers[d_reg] += b_reg / (address);
		break;
	case 001111:  //001111(2) = 0F(16), Instruction: LDI
		registers[d_reg] = address;
		break;
	case 010001:  //010001(2) = 11(16), Instruction: SLTI
		if (registers[b_reg] < (address)){
			registers[d_reg] = 1;
		}
		else{
			registers[d_reg] = 0;
		}
		break;

		//TODO: CPU doesn't need programcounter, these need to change the location of the program counter of the 
		//process that's currently running. This should be as simple as setting the currentIndex variable of RAM
		//to the value of (address / 4) since currentIndex acts as the iterator, or programCounter per se.
	case 010101:  //010101(2) = 15(16), Instruction: BEQ
		if (registers[b_reg] == registers[d_reg]){
			programCounter = (address / 4);
		}
		break;
	case 010110:  //010110(2) = 16(16), Instruction: BNE
		if (registers[b_reg] != registers[d_reg]){
			programCounter = (address / 4);
		}
		break;
	case 010111:  //010111(2) = 17(16), Instruction: BEZ
		if (registers[d_reg] == registers[1]){
			programCounter = (address / 4);
		}
		break;
	case 011000:  //011000(2) = 18(16), Instruction: BNZ
		if (registers[d_reg] != registers[1]){
			programCounter = (address / 4);
		}
		break;
	case 011001:  //011001(2) = 19(16), Instruction: BGZ
		if (registers[d_reg] > registers[1]){
			programCounter = (address / 4);
		}
		break;
	case 011010:  //011010(2) = 1A(16), Instruction: BLZ
		if (registers[d_reg] < registers[1]){
			programCounter = (address / 4);
		}
		break;
	case 000010: //000010(2) = 2(16), Instruction: ST
		registers[address] += registers[d_reg];
		break;
	case 000011: //000011(2) = 3(16), Instruction: LW
		//Add content of address to base reg, then store that in the destination register
		registers[d_reg] = registers[address + registers[b_reg]];
		break;

	default: break;
	}
};

//Case 10, Unconditional Jump format using "J" type instructions:
//HLT JMP
void CPU::jumpFormat(string binary, int &programCounter){
	//convert opcode into integral type for switch
	bitset<6> oc(binary.substr(2, 6));
	int opcode = oc.to_ulong();

	//convert binary substrings to decimal integers for accessing registers by index properly
	int address = stoi(binary.substr(8, 24), nullptr, 2);

	switch (opcode)
	{
	case 010010:  //HLT
		cout << "Halt command encountered." << endl;
		break;
	case 010100: //JMP
		programCounter = (address);
		break;

	default: break;
	}
};

//Case 11, Input/Output format using "IO" type instructions:
//RD WR
void CPU::ioFormat(string binary, PCB &currentProc){
	//convert opcode into integral type for switch
	bitset<6> oc(binary.substr(2, 6));
	int opcode = oc.to_ulong();
	int writeReg;
	istringstream iss;
	string readContent, writeContent;

	//convert binary substrings to decimal integers for accessing registers by index properly
	int reg_1 = stoi(binary.substr(8, 4), nullptr, 2);
	int reg_2 = stoi(binary.substr(12, 4), nullptr, 2);
	int address = stoi(binary.substr(16, 16), nullptr, 2);

	switch (opcode){
	
	case 000000: //RD, Reads content of the input buffer into the accumulator
		address = currentProc.startRam + (address / 4);
		readContent = testRam.memory[address];
		registers[accumulator] += stoi(readContent, nullptr, 16);
	case 000001: //WR, Writes the content of the accumulator into the output buffer
		address = currentProc.startRam + (address / 4);
		writeReg = registers[accumulator];
		iss >> std::dec >> writeReg;
		testRam.memory[address] = writeReg;
	default: break;
	}
};

void CPU::loadCPU(PCB currentProc){
	vector<string> temp;
	currentProc.endWaitTime = std::chrono::high_resolution_clock::now();
	currentProc.startExecuteTime = std::chrono::high_resolution_clock::now();
	temp = fetch(currentProc);
	temp = decode(temp);
	for (currentProc.programCounter; currentProc.programCounter <= temp.size(); currentProc.programCounter++){
		execute(temp[currentProc.programCounter], currentProc);
	}
	currentProc.endExecuteTime = std::chrono::high_resolution_clock::now();
	cout << "Total wait time for process #" << currentProc.jobID << "is :" << currentProc.elapsedTime(currentProc.startWaitTime, currentProc.endWaitTime);
	cout << "Total execution time for process #" << currentProc.jobID << "is :" << currentProc.elapsedTime(currentProc.startExecuteTime, currentProc.endExecuteTime);
}