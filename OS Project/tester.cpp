#include "disk.h"
#include "CPU.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

int main(){
	CPU cpu;
	Disk testDisk;

	testDisk.loader();
	//testDisk.longschedler();

	cpu.decode("0x0123ABC");

	system("pause");
}