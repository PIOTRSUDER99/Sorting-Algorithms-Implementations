#include "Sorting.h"

void InsertionSort(vector<int> *Array)
{


	//int sortedEdge = 0; //index of the last element in the sorted region
	for (unsigned int i = 1; i < Array->size(); i++)
	{
		int entry = Array->at(i);
		int j = i - 1;
		while (j >= 0) 
		{
			if (entry > Array->at(j))
			{
				break;
			}
			j -= 1;
		}

		for (int k = i - 1; k >= j + 1; k--)
		{
			Array->at(k + 1) = Array->at(k);
		}
		Array->at(j + 1) = entry;
	}


}



void QuickSort(vector<int> *Array)
{
	QuickSortRecursive(Array, 0, Array->size() - 1);
}


void QuickSortRecursive(vector<int> *Array, int BeginIndex, int endIndex) 
{
	if (BeginIndex < endIndex)
	{
		int pivot = partition(Array, BeginIndex, endIndex);
		QuickSortRecursive(Array, BeginIndex, pivot - 1);
		QuickSortRecursive(Array, pivot + 1, endIndex);
	}
}

int partition(vector<int> *Array, int beginIndex, int endIndex)
{
	
	if (endIndex - beginIndex >= 3)
	{
		//choosing pivot
		vector<unsigned int> RandomEntries;
		unsigned int randInt;
		for (unsigned int n = 0; n < 3; n++)
		{
			randInt = rand() % (endIndex - beginIndex);
			randInt += beginIndex;
			RandomEntries.push_back(randInt);
		}

		//find middle element in RandomEntries array
		unsigned int maxEntry = Array->at(RandomEntries.at(0));
		unsigned int maxEntryIndex = 0;
		unsigned int middleIndex;
		for (unsigned int n = 0; n < RandomEntries.size(); n++)
		{
			if (Array->at(RandomEntries.at(n)) > maxEntry)
			{
				maxEntry = Array->at(RandomEntries.at(n));
				maxEntryIndex = n;
			}
		}

		//remove element at maxEntryIndex
		RandomEntries.erase(RandomEntries.begin() + maxEntryIndex);

		if (Array->at(RandomEntries.at(0)) < Array->at(RandomEntries.at(1)))
		{
			middleIndex = RandomEntries.at(1);
		}
		else
		{
			middleIndex = RandomEntries.at(0);
		}

		//swap Array[middle] with Array[beginIndex]
		int tempKey = Array->at(middleIndex);
		Array->at(middleIndex) = Array->at(beginIndex);
		Array->at(beginIndex) = tempKey;
	}
	

	int pivot = Array->at(beginIndex);
	int i = beginIndex;

	int temp = 0;

	for (int j = beginIndex + 1; j <= endIndex; j++)
	{
		if (Array->at(j) <= pivot)
		{
			i++;
			temp = Array->at(j);
			Array->at(j) = Array->at(i);
			Array->at(i) = temp;
		}
	}

	temp = Array->at(i);
	Array->at(i) = Array->at(beginIndex);
	Array->at(beginIndex) = temp;

	return i;
}



void MergeSort(vector<int> *Array)
{
	MergeSortRecursive(Array, 0, Array->size() - 1);
}

void MergeSortRecursive(vector<int> *Array, int beginIndex, int endIndex)
{
	if (beginIndex < endIndex)
	{
		int middleIndex = (beginIndex + endIndex) / 2;
		MergeSortRecursive(Array, beginIndex, middleIndex);
		MergeSortRecursive(Array, middleIndex + 1, endIndex);
		Merge(Array, beginIndex, middleIndex, middleIndex + 1, endIndex);
	}
}

void Merge(vector<int> *Array, int beginIndex1, int endIndex1, int beginIndex2, int endIndex2)
{
	vector<int> OutsideArray;
	unsigned int i = beginIndex1;
	unsigned int j = beginIndex2;

	while (i <= endIndex1 && j <= endIndex2)
	{
		if (Array->at(i) <= Array->at(j))
		{
			OutsideArray.push_back(Array->at(i));
			i++;
		}
		else
		{
			OutsideArray.push_back(Array->at(j));
			j++;
		}
	}
	 while(i <= endIndex1)
	{
		 OutsideArray.push_back(Array->at(i));
		 i++;
	}

	 while (j <= endIndex2)
	 {
		 OutsideArray.push_back(Array->at(j));
		 j++;
	 }

	 //copy the entries back to Array
	 for (unsigned int k = 0; k < OutsideArray.size(); k++)
	 {
		 Array->at(beginIndex1 + k) = OutsideArray.at(k);
	 }
}
