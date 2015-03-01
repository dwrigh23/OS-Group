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
	hex.erase(0, 1);
	for (int i = 0; i != hex.length(); i++){
		binary += hexSwitch(hex[i]);
	}
	cout << binary;
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
