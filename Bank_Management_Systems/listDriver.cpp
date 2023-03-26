// Test driver
#include "sorted.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>


using namespace std;

int main()
{

	SortedType<int> myLst;

	myLst.PutItem(5);
	myLst.PutItem(2);
	myLst.PutItem(7);
	myLst.PutItem(11);
	myLst.PutItem(1);

	myLst.ResetList();
	for (int i=0; i < myLst.GetLength(); i++) {
		cout << myLst.GetNextItem() << endl;
	}

	return 0;

}

