#pragma once

#include<iostream>
#include <vector>
#include <stdlib.h>

#include <chrono>
#include <iomanip>
#include <string>

#include <fstream>

#include "Sorting.h"



using namespace std;
using std::ifstream;
using std::ofstream;

void generateFiles();

long long RunSortSpecific(string sortType, vector<int> *ArrayToSort);

void TestForOrderType(string orderType, unsigned int FileSize);

void RunSorts();