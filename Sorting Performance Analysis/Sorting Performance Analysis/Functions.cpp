
#include "Functions.h"


using namespace std;
using std::ifstream;
using std::ofstream;



void generateFiles()
{
	vector<int> FileSizes = { 10000, 20000, 50000, 100000 };



	ofstream outFile;
	string s;
	string fileName;
	for (unsigned int i = 0; i < FileSizes.size(); i++)
	{
		//Random
		int randInt = 0;
		s = to_string(FileSizes.at(i));
		fileName = "Random" + s + ".txt";
		outFile.open(fileName);

		for (unsigned int j = 0; j < FileSizes.at(i); j++)
		{
			randInt = rand() % (2 * FileSizes.at(i));
			outFile << randInt << endl;
		}

		outFile.close();


		//Ascending
		fileName = "Ascending" + s + ".txt";
		outFile.open(fileName);

		for (unsigned int j = 0; j < FileSizes.at(i); j++)
		{
			outFile << j + 1 << endl;
		}

		outFile.close();


		//Descending
		fileName = "Descending" + s + ".txt";
		outFile.open(fileName);

		for (unsigned int j = 0; j < FileSizes.at(i); j++)
		{
			outFile << FileSizes.at(i) - j << endl;
		}

		outFile.close();

	}

}


//sortType: "Insertion", "Merge", "Quick"
//returns time in microseconds
long long RunSortSpecific(string sortType, vector<int> *ArrayToSort)
{


	auto start = std::chrono::high_resolution_clock::now();

	auto elapsed = std::chrono::high_resolution_clock::now() - start;
	long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();



	//Insertion Sort==================================================================================
	if (sortType == "Insertion")
	{

		//TIMING-------------------------------------------
		start = std::chrono::high_resolution_clock::now();

		InsertionSort(ArrayToSort);

		elapsed = std::chrono::high_resolution_clock::now() - start;
		microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

	}


	//Merge Sort==================================================================================
	if (sortType == "Merge")
	{
		//TIMING-------------------------------------------
		start = std::chrono::high_resolution_clock::now();

		MergeSort(ArrayToSort);

		elapsed = std::chrono::high_resolution_clock::now() - start;
		microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

	}


	//Quick Sort==================================================================================
	if (sortType == "Quick")
	{

		//TIMING-------------------------------------------
		start = std::chrono::high_resolution_clock::now();

		QuickSort(ArrayToSort);

		elapsed = std::chrono::high_resolution_clock::now() - start;
		microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

	}


	return microseconds;
}






//orderType: "Random", "Ascending", "Descending"
void TestForOrderType(string orderType, unsigned int FileSize)
{
	string fileName;
	string s;
	string line;
	int number;
	int numRepeats = 7;
	vector<string> SortTypes = { "Insertion", "Merge", "Quick" };

	long long microseconds = 0;
	long long totalMicroseconds = 0;

	vector<int> Array;
	vector<int> ArrayToSort;


	Array.clear();
	s = to_string(FileSize);
	fileName = orderType + s + ".txt";

	ifstream inFile;

	inFile.open(fileName);

	while (getline(inFile, line))
	{
		number = stoi(line);
		Array.push_back(number);
	}

	ArrayToSort.clear();
	for (unsigned int j = 0; j < Array.size(); j++)
	{
		ArrayToSort.push_back(Array.at(j));
	}


	cout << orderType << " Order============================================" << endl;
	cout << endl;

	for (unsigned int i = 0; i < SortTypes.size(); i++)
	{
		cout << SortTypes.at(i) << " Sort" << endl;

		totalMicroseconds = 0;
		for (unsigned int k = 0; k < numRepeats; k++)
		{
			microseconds = RunSortSpecific(SortTypes.at(i), &ArrayToSort);
			totalMicroseconds += microseconds;

			ArrayToSort.clear();
			for (unsigned int j = 0; j < Array.size(); j++)
			{
				ArrayToSort.push_back(Array.at(j));
			}
		}



		cout << "Average time elapsed: " << (totalMicroseconds / numRepeats) << endl;
		cout << endl;
		cout << endl;

	}


}



void RunSorts()
{
	vector<int> FileSizes = { 10000, 20000, 50000, 100000 };
	vector<string> OrderTypes = { "Random", "Ascending", "Descending" };

	for (unsigned int i = 0; i < FileSizes.size(); i++)
	{
		cout << "Number of items in the array: " << FileSizes.at(i) << endl;
		cout << endl;

		for (unsigned int j = 0; j < OrderTypes.size(); j++)
		{
			TestForOrderType(OrderTypes.at(j), FileSizes.at(i));
		}

		cout << "***********************************************************************" << endl;
		cout << "***********************************************************************" << endl;
		cout << "***********************************************************************" << endl;
		cout << "***********************************************************************" << endl;
		cout << endl;
		cout << endl;


	}

}


