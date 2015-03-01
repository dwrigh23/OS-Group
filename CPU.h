//Aaron Settle
//2-28-2015
//OS Project
#ifndef CPU_H 
#define CPU_H
#include <string>

using namespace std;

class CPU{
private:
	
public:

	string fetch();

	string hexToBin(string hex);
	
	const char* hexSwitch(char hex);

	string decode(string binary);
};

class Execute{
private:

public:
		//Case 00
		//Ins:RD, Type:IO, Read contents of IP buffer into an accumulator
		void read();
		//Case 01
		//Ins:WR, Type:IO, Write contents of accumulator into OP buffer
		void write();
		//Case 02
		//Ins:ST, Type:Imm, Store contents of a register into an address
		void store();
		//Case 03
		//Ins:LW, Type:Imm, Load content of an address into a register
		void loadAddress();
		//Case 04
		//Ins:MOV, Type:Reg, Transfers the content of 1 register into another
		void regMove();
		//Case 05
		//Ins:ADD, Type:Reg, Add content of 2 S-reg into D-reg
		void regAdd();
		//Case 06
		//Ins:SUB, Type:Reg, Subtract content of 2 S-reg into D-reg
		void regSubtract();
		//Case 07
		//Ins:MUL, Type:Reg, Multiply content of 2 S-reg into D-reg
		void regMultiply();
		//Case 08
		//Ins:DIV, Type:Reg, Divide content of 2 S-reg into D-reg
		void regDivide();
		//Case 09
		//Ins:AND, Type:Reg, Logical AND of 2 S-reg into D-reg
		void regLogicAnd();
		//Case 0A
		//Ins:OR, Type:Reg, Logical OR of 2 S-reg into D-reg
		void regLogicOr();
		//Case 0B
		//Ins:MOVI, Type:Imm, Transfers address/data directly into reg
		void transferData();
		//Case 0C
		//Ins:ADDI, Type:Imm, Adds a data rirectly to the content of a reg
		void addData();
		//Case 0D
		//Ins:MULI, Type:Imm, Multiplies a data directly to the content of a reg
		void multiplyData();
		//Case 0E
		//Ins:DIVI, Type:Imm, Divides a data directly to the content of a reg
		void divideData();
		//Case 0F
		//Ins:LDI, Type:Imm, Loads a data/address directly to the content of a reg
		void loadData();
		//Case 10
		//Ins:SLT, Type:Reg, Sets the D-reg to 1 if 1st S-reg < 2nd B-reg, 0 otherwise
		void setLessReg();
		//Case 11
		//Ins:SLTI, Type:Imm, Sets the D-reg to 1 if 1st S-reg < a data, 0 otherwise
		void setLessData();
		//Case 12
		//Ins:HLT, Type:Jmp, Logical end of program
		void halt();
		//Case 13
		//Ins:NOP, Type:--, Does nothing and moves to next instruction
		void nothing();
		//Case 14
		//Ins:JMP, Type:jmp, Jumps to a specified location
		void jump();
		//Case 15
		//Ins:BEQ, Type:Imm, Branches to an address when content of B-reg = D-reg
		void branchED();
		//Case 16
		//Ins:BNE, Type:Imm, Branches to an address when content of B-reg <> D-reg
		void branchNED();
		//Case 17
		//Ins:BEZ, Type:Imm, Branches to an address when content of B-reg = 0
		void branchEZ();
		//Case 18
		//Ins:BNZ, Type:Imm, Branches to an address when content of B-reg <> 0
		void branchNEZ();
		//Case 19
		//Ins:BGZ, Type:Imm, Branches to an address when content of B-reg > 0
		void branchGZ();
		//Case 1A
		//Ins:BLZ, Type:Imm, Branches to an address when content of B-reg < 0
		void branchLZ();
};

#endif
