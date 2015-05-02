//Aaron Settle
//2-28-2015
//OS Project
#include "CPU.h"
#include <iomanip>
#include <bitset>
#include <string>
#include <iostream>
#include <sstream>
#include <chrono>

using namespace std;

void CPU::resetRegisters(){
	for (int i = 0; i < 16; i++){
		registers[i] = 0;
	}
}

vector<string> CPU::fetch(PCB currentProc){
	string currentInstr;
	vector<string> instrList;

	for (int i = currentProc.startRam; i <= currentProc.endRam; i++){
		currentInstr = testRam.memory[i];
		instrList.push_back(currentInstr);
	}
	return instrList;
};

vector<string> CPU::decode(vector<string> &instrList){
	string binary;
	vector<string> decodedInstr;
	for (int i = 0; i < instrList.size(); i++){
		instrList[i].erase(0, 2);
		for (int j = 0; j != instrList[i].length(); ++j){
			binary += hexSwitch(instrList[i].at(j));
		}
		decodedInstr.push_back(binary);
		binary = "";
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
			branchFormat(binary, currentProc.programCounter, currentProc);
		}
		//Case 3: If substring == "10"
		//Conditional jump format
		if (caseBits == "10"){
			jumpFormat(binary, currentProc.programCounter, currentProc);
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
	case 4:  //000100(2) = 04(16), Instruction: MOV
		cout << "OPCODE: MOV, CONTENTS SRC_REG: " << src_reg << " SRC_REG2 " << src_reg2 << endl;
		registers[src_reg] = registers[src_reg2];
		cout << "RESULT: " << registers[src_reg] << endl;
		break;
	case 5:  //000101(2) = 05(16), Instruction: ADD
		cout << "OPCODE: ADD, CONTENTS SRC_REG: " << src_reg << " SRC_REG2 " << src_reg2 << endl;
		registers[dest_reg] = registers[src_reg] + registers[src_reg2];
		cout << "RESULT: " << registers[dest_reg] << endl;
		break;
	case 6:  //000110(2) = 06(16), Instruction: SUB
		cout << "OPCODE: SUB, CONTENTS SRC_REG: " << src_reg << " SRC_REG2 " << src_reg2 << endl;
		registers[dest_reg] = registers[src_reg] - registers[src_reg2];
		cout << "RESULT: " << registers[dest_reg] << endl;
		break;
	case 7:  //000111(2) = 07(16), Instruction: MUL
		cout << "OPCODE: MUL, CONTENTS SRC_REG: " << src_reg << " SRC_REG2 " << src_reg2 << endl;
		registers[dest_reg] = registers[src_reg] * registers[src_reg2];
		cout << "RESULT: " << registers[dest_reg] << endl;
		break;
	case 8:  //001000(2) = 08(16), Instruction: DIV
		cout << "OPCODE: DIV, CONTENTS SRC_REG: " << src_reg << " SRC_REG2 " << src_reg2 << endl;
		if (registers[src_reg2] == 0){
			cout << "Cannot divide by 0" << endl;
		}
		else{
			registers[dest_reg] = registers[src_reg] / registers[src_reg2];
			cout << "RESULT: " << registers[dest_reg] << endl;
		}
		break;
	case 9:  //001001(2) = 09(16), Instruction: AND
		cout << "OPCODE: AND, CONTENTS SRC_REG: " << src_reg << " SRC_REG2 " << src_reg2 << endl;
		registers[dest_reg] = src_reg & src_reg2;
		cout << "RESULT: " << registers[dest_reg] << endl;
		break;
	case 10:  //001010(2) = 0A(16), Instruction: OR
		cout << "OPCODE: OR, CONTENTS SRC_REG: " << src_reg << " SRC_REG2 " << src_reg2 << endl;
		registers[dest_reg] = src_reg | src_reg2;
		cout << "RESULT: " << registers[dest_reg] << endl;
		break;
	case 16:  //010000(2) = 10(16), Instruction: SLT
		cout << "OPCODE: SLT, CONTENTS SRC_REG: " << src_reg << " SRC_REG2 " << src_reg2 << endl;
		if (registers[src_reg] < registers[src_reg2]){
			registers[dest_reg] = 1;
			cout << "RESULT: " << registers[dest_reg] << endl;
		}
		else{
			registers[dest_reg] = 0;
			cout << "RESULT: " << registers[dest_reg] << endl;
		}
		break;
	
	default: break;
	}
};

//Case 01, Conditional Brance and Immediate format using "I" type instructions:
//ST LW MOVI ADDI MULI DIVI LDI SLTI BEQ BNE BEZ BNZ BGS BLZ
void CPU::branchFormat(string binary, int &programCounter, PCB currentProc){
	//convert opcode into integral type for switch
	bitset<6> oc(binary.substr(2, 6));
	int opcode = oc.to_ulong();
	string data;
	int usableData;

	//convert binary substrings to decimal integers for accessing registers by index properly
	int b_reg = stoi(binary.substr(8, 4), nullptr, 2);
	int d_reg = stoi(binary.substr(12, 4), nullptr, 2);
	int address = stoi(binary.substr(16, 16), nullptr, 2); 
	switch (opcode)
	{
	case 11:  // 001011(2) = 0B(16), Instruction: MOVI
		cout << "OPCODE: MOVI, CONTENTS ADDRESS: " << address << endl;
		if (address > 1){
			address += currentProc.codeSize;
			data = testRam.memory[address];
			data = data.substr(2);
			usableData = stoi(data, nullptr, 16);
			registers[d_reg] = usableData;
		}
		else{
			registers[d_reg] = address;
		}
		cout << "RESULT: " << registers[d_reg] << endl;
		break;
	case 12:  //001100(2) = 0C(16), Instruction: ADDI
		cout << "OPCODE: ADDI, CONTENTS B_REG: " << b_reg << " ADDRESS " << address << endl;
		registers[d_reg] += address;
		cout << "RESULT: " << registers[d_reg] << endl;
		break;
	case 13:  //001101(2) = 0D(16), Instruction: MULI
		cout << "OPCODE: MULI, CONTENTS B_REG: " << b_reg << " ADDRESS " << address << endl;
		registers[d_reg] += (address);
		cout << "RESULT: " << registers[d_reg] << endl;
		break;
	case 14:  //001110(2) = 0E(16), Instruction: DIVI
		cout << "OPCODE: DIVI, CONTENTS B_REG: " << b_reg << " ADDRESS " << address << endl;
		registers[d_reg] /= address;
		cout << "RESULT: " << registers[d_reg] << endl;
		break;
	case 15:  //001111(2) = 0F(16), Instruction: LDI
		cout << "OPCODE: MULI, CONTENTS ADDRESS: " << address << endl;
		registers[d_reg] = address;
		cout << "RESULT: " << registers[d_reg] << endl;
		break;
	case 17:  //010001(2) = 11(16), Instruction: SLTI
		cout << "OPCODE: MULI, CONTENTS B_REG: " << b_reg << " ADDRESS " << address << endl;
		if (registers[b_reg] < address){
			registers[d_reg] = 1;
			cout << "RESULT: " << registers[d_reg] << endl;
		}
		else{
			registers[d_reg] = 0;
			cout << "RESULT: " << registers[d_reg] << endl;
		}
		break;

	case 21:  //010101(2) = 15(16), Instruction: BEQ
		cout << "OPCODE: BEQ, CONTENTS B_REG: " << registers[b_reg] << " D_REG " << registers[d_reg] << endl;
		if (registers[b_reg] == registers[d_reg]){
			programCounter = address;
		}
		break;
	case 22:  //010110(2) = 16(16), Instruction: BNE
		cout << "OPCODE: BNE, CONTENTS B_REG: " << registers[b_reg] << " D_REG " << registers[d_reg] << endl;
		if (registers[b_reg] != registers[d_reg]){
			programCounter = address;
		}
		break;
	case 23:  //010111(2) = 17(16), Instruction: BEZ
		cout << "OPCODE: BEZ, CONTENTS D_REG: " << registers[d_reg] << " ZERO REG " << registers[1] << endl;
		if (registers[d_reg] == 0){
			programCounter = address;
		}
		break;
	case 24:  //011000(2) = 18(16), Instruction: BNZ
		cout << "OPCODE: BNZ, CONTENTS D_REG: " << registers[d_reg] << " ZERO REG " << registers[1] << endl;
		if (registers[d_reg] != 0){
			programCounter = address;
		}
		break;
	case 25:  //011001(2) = 19(16), Instruction: BGZ
		cout << "OPCODE: BGZ, CONTENTS D_REG: " << registers[d_reg] << " ZERO REG " << registers[1] << endl;
		if (registers[d_reg] > 0){
			programCounter = address;
		}
		break;
	case 26:  //011010(2) = 1A(16), Instruction: BLZ
		cout << "OPCODE: BLZ, CONTENTS D_REG: " << registers[d_reg] << " ZERO REG " << registers[1] << endl;
		if (registers[d_reg] < 0){
			programCounter = address;
		}
		break;
	case 2: //000010(2) = 2(16), Instruction: ST
		cout << "OPCODE: ST, CONTENTS ADDRESS: " << registers[address] << " D_REG " << registers[d_reg] << endl;
		registers[address] += registers[d_reg];
		cout << "RESULT: " << registers[address] << endl;
		break;
	case 3: //000011(2) = 3(16), Instruction: LW
		//Add content of address to base reg, then store that in the destination register
		cout << "OPCODE: LW, CONTENTS ADDRESS: " << address << " B_REG " << b_reg << endl;
		registers[d_reg] = registers[(address + registers[b_reg]) % 16];
		cout << "RESULT: " << registers[d_reg] << endl;
		break;

	default: break;
	}
};

//Case 10, Unconditional Jump format using "J" type instructions:
//HLT JMP
void CPU::jumpFormat(string binary, int &programCounter, PCB currentProc){
	//convert opcode into integral type for switch
	bitset<6> oc(binary.substr(2, 6));
	int opcode = oc.to_ulong();
	
	//convert binary substrings to decimal integers for accessing registers by index properly
	int address = stoi(binary.substr(8, 24), nullptr, 2);

	switch (opcode)
	{
	case 18:  //HLT
		currentProc.endExecuteTime = chrono::high_resolution_clock::now();
		cout << "OPCODE: HLT" << endl;
		cout << "Halt command encountered. Process finished." << endl;
		currentProc.processState = currentProc.terminated;
		break;
	case 20: //JMP
		cout << "OPCODE: JMP, CONTENTS ADDRESS: " << address << endl;
		programCounter = address;
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
	
	case 0: //RD, Reads content of the input buffer into the accumulator
		cout << "OPCODE: RD" << endl;
		address = (currentProc.startRam + currentProc.codeSize + (address / 4));
		readContent = testRam.memory[address];
		registers[accumulator] += stoi(readContent, nullptr, 16);
		break;
	case 1: //WR, Writes the content of the accumulator into the output buffer
		cout << "OPCODE: WR" << endl;
		address = currentProc.codeSize + address;
		writeReg = registers[accumulator];
		iss >> std::dec >> writeReg;
		testRam.memory[address] = writeReg;
		break;
	default: break;
	}
};

void CPU::loadCPU(PCB currentProc){
	vector<string> fetched, decoded;
	currentProc.endWaitTime = std::chrono::high_resolution_clock::now();
	currentProc.startExecuteTime = std::chrono::high_resolution_clock::now();
	fetched = fetch(currentProc);
	cout << "Fetch successful...Decoding now." << endl;
	decoded = decode(fetched);
	cout << "Decode succcesful...performing execute." << endl;
	for (currentProc.programCounter; currentProc.programCounter < decoded.size(); currentProc.programCounter++){
		if (currentProc.processState == currentProc.terminated){
			break;
		}
		else{ 
			if (currentProc.programCounter == 0){
				currentProc.processState = currentProc.running;
				execute(decoded[currentProc.programCounter], currentProc);
			}
			else{
				execute(decoded[currentProc.programCounter], currentProc);
			}
		}
	}
	currentProc.endExecuteTime = std::chrono::high_resolution_clock::now();
	testRam.currentIndex = 0;
	cout << "Execute successful." << endl;
}