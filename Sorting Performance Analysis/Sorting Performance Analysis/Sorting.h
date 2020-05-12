#pragma once
#include <iostream>
#include <vector>;

using namespace std;

void InsertionSort(vector<int> *Array);

void QuickSort(vector<int> *Array);

void QuickSortRecursive(vector<int> *Array, int BeginIndex, int endIndex);

int partition(vector<int> *Array, int beginIndex, int endIndex);

void MergeSort(vector<int> *Array);

void MergeSortRecursive(vector<int> *Array, int beginIndex, int endIndex);

//we assume that we are merging together adjacent regions of the array
void Merge(vector<int> *Array, int beginIndex1, int endIndex1, int beginIndex2, int endIndex2);