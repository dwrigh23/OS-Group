//Aaron Settle
//2-28-2015
//OS Project
#include "CPU.h"
#include <iostream>
#include <string>
#include<bitset>

/*string CPU::fetch(){

};*/

string CPU::hexToBin(string hex){
	string binary;
	hex.erase(0, 2);
	for (int i = 0; i != hex.length(); ++i){
		binary += hexSwitch(hex[i]);
	}
	cout << binary << endl;
	return binary;
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
/*string CPU::decode(string binary){


};*/


/*
//Case 00
//Ins:RD, Type:IO, Read contents of IP buffer into an accumulator
void Execute::read(){};
//Case 01
//Ins:WR, Type:IO, Write contents of accumulator into OP buffer
void Execute::write(){};
//Case 02
//Ins:ST, Type:Imm, Store contents of a register into an address
void Execute::store(){};
//Case 03
//Ins:LW, Type:Imm, Load content of an address into a register
void Execute::loadAddress(){};
//Case 04
//Ins:MOV, Type:Reg, Transfers the content of 1 register into another
void Execute::regMove(){};
//Case 05
//Ins:ADD, Type:Reg, Add content of 2 S-reg into D-reg
void Execute::regAdd(){};
//Case 06
//Ins:SUB, Type:Reg, Subtract content of 2 S-reg into D-reg
void regSubtract(){};
//Case 07
//Ins:MUL, Type:Reg, Multiply content of 2 S-reg into D-reg
void Execute::regMultiply(){};
//Case 08
//Ins:DIV, Type:Reg, Divide content of 2 S-reg into D-reg
void Execute::regDivide(){};
//Case 09
//Ins:AND, Type:Reg, Logical AND of 2 S-reg into D-reg
void Execute::regLogicAnd(){};
//Case 0A
//Ins:OR, Type:Reg, Logical OR of 2 S-reg into D-reg
void Execute::regLogicOr(){};
//Case 0B
//Ins:MOVI, Type:Imm, Transfers address/data directly into reg
void Execute::transferData(){};
//Case 0C
//Ins:ADDI, Type:Imm, Adds a data rirectly to the content of a reg
void Execute::addData(){};
//Case 0D
//Ins:MULI, Type:Imm, Multiplies a data directly to the content of a reg
void Execute::multiplyData(){};
//Case 0E
//Ins:DIVI, Type:Imm, Divides a data directly to the content of a reg
void Execute::divideData(){};
//Case 0F
//Ins:LDI, Type:Imm, Loads a data/address directly to the content of a reg
void Execute::loadData(){};
//Case 10
//Ins:SLT, Type:Reg, Sets the D-reg to 1 if 1st S-reg < 2nd B-reg, 0 otherwise
void Execute::setLessReg(){};
//Case 11
//Ins:SLTI, Type:Imm, Sets the D-reg to 1 if 1st S-reg < a data, 0 otherwise
void Execute::setLessData(){};
//Case 12
//Ins:HLT, Type:Jmp, Logical end of program
void Execute::halt(){};
//Case 13
//Ins:NOP, Type:--, Does nothing and moves to next instruction
void Execute::nothing(){};
//Case 14
//Ins:JMP, Type:jmp, Jumps to a specified location
void Execute::jump(){};
//Case 15
//Ins:BEQ, Type:Imm, Branches to an address when content of B-reg = D-reg
void Execute::branchED(){};
//Case 16
//Ins:BNE, Type:Imm, Branches to an address when content of B-reg <> D-reg
void Execute::branchNED(){};
//Case 17
//Ins:BEZ, Type:Imm, Branches to an address when content of B-reg = 0
void Execute::branchEZ(){};
//Case 18
//Ins:BNZ, Type:Imm, Branches to an address when content of B-reg <> 0
void Execute::branchNEZ(){};
//Case 19
//Ins:BGZ, Type:Imm, Branches to an address when content of B-reg > 0
void Execute::branchGZ(){};
//Case 1A
//Ins:BLZ, Type:Imm, Branches to an address when content of B-reg < 0
void Execute::branchLZ(){};
};
*/
