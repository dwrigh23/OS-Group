#include "disk.h"
#include "RAM.h"
#include "PCB.h"
#include "CPU.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

int main(){
	CPU cpu;

	testDisk.loader();

	//cpu.decode("0x0123ABC");

	system("pause");
}