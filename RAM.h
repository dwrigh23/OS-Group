//Aaron Settle
//3-3-2015
//OS Project
#ifndef RAM_H 
#define RAM_H
#include <vector>

using namespace std;

class RAM {
private:

public:
	vector<string> memory[1024];
	int current;
	int free;
};

#endif
