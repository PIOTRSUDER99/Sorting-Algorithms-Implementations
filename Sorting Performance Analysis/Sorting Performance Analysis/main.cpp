#include<iostream>
#include <vector>
#include <stdlib.h>
#include <chrono>
#include <iomanip>
#include <string>
#include <fstream>

#include "Sorting.h"
#include "Functions.h"

using namespace std;
using std::ifstream;
using std::ofstream;

int main() {

	int option = 0;
	
	cout << "1. Generate test files." << endl;
	cout << "2. Run the sorts." << endl;
	cin >> option;
	cout << endl;

	if (option == 1)
	{
		generateFiles();
		cout << "Done" << endl;
	}
	if (option == 2)
	{
		RunSorts();
		cout << "Done" << endl;
	}

	int noth2;
	cin >> noth2;
	return 0;	
}