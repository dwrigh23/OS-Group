//Aaron Settle
//3-1-2015
//OS Project
#ifndef CPU_H 
#define CPU_H
#include <string>

using namespace std;

class CPU{
private:
	
public:
	//array of 16 "registers"
	int registers[16];

	//Retrieve an instruction from the disk
	string fetch();

	//Convert instructions to binary format (Base 2)
	string decode(string hex);
	
	//Hex to binary "Repository", if you will
	const char* hexSwitch(char hex);

	//Analyze and decode instruction that has been converted from Hex to Binary
	void execute(string binary);

	//Case 00, register transfer using 2 sources and 1 destination
	//so this uses the "R" type instructions of: MOV ADD SUB MUL DIV AND OR SLT
	void arithmeticFormat(string binary);

	//Case 01, Conditional Brance and Immediate format using "I" type instructions:
	//ST LW MOVI ADDI MULI DIVI LDI SLTI BEQ BNE BEZ BNZ BGS BLZ
	void branchFormat(string binary);

	//Case 10, Unconditional Jump format using "J" type instructions:
	//HLT JMP
	void jumpFormat(string binary);

	//Case 11, Input/Output format using "IO" type instructions:
	//RD WR
	void ioFormat(string binary);
};
CPU cpu;

#endif
