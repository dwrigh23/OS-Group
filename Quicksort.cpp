#include "QS.h"
#include <iostream>
#include <time.h>

using namespace std;

//Partitions the vector correctly so using comparisons to pivot
int partition(vector<int>& test, int left, int right)
{
	int pivot = test[left];
	int i = left;

	for (int j = left + 1; j < right; j++)
	{
		if (test[j] <= pivot)
		{
			i = i + 1;
			swap(test[i], test[j]);
		}

	}

	swap(test[i], test[left]);
	return i;
}

//Actual quicksort algorithm, mostly self-explanatory
void quickSort(vector<int>& test, int left, int right)
{
	if (left < right)
	{
		int r = partition(test, left, right); //Partitions vector
		cout << "Partitioned vector: " << endl;
		for (int i = 0; i < 10; i++){			//This loop prints the testArray's elements for the user
			cout << test[i] << " ";
		}
		cout << endl;
		quickSort(test, left, r); //Quicksort using left index
		quickSort(test, r + 1, right); //Finishes quicksort using right index
	}
}


int main(){
	int size = 10;	//sentinel value
	vector<int> testVec;	//vector we will use for random numbers

	srand(time(NULL));	//random number initial seed

	for (int i = 0; i < size; i++){			//This loop provides 10 random numbers between -10 and 19
		int random = rand() % 29 + (-9);	//and stores them in the testVec
		testVec.push_back(random);
	}

	cout << "Original Vector contains:";

	for (int i = 0; i < size; i++){			//This loop prints the testVec's elements for the user
		cout << testVec[i] << " ";
	}
	cout << endl;

	quickSort(testVec, 0, size);

	cout << "Sorted Vector contains:";

	for (int i = 0; i < size; i++){			//This loop prints the testVec's elements for the user
		cout << testVec[i] << " ";
	}
	cout << endl;

	system("pause");
}
