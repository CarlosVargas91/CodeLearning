//#include "stdafx.h"
#include <iostream>
#include <chrono>
#include <ctime>
#include <stdlib.h>

#define USE_SMALL
#define USE_MEDIUM
//#define USE_LARGE

#define SMALL_SIZE  100
#define MEDIUM_SIZE 100000
#define LARGE_SIZE  100000000

int small [SMALL_SIZE] ;
int medium[MEDIUM_SIZE];
int large [LARGE_SIZE] ;

void init() 
{
#ifdef USE_SMALL
	for (auto i = 0; i < SMALL_SIZE; i++)
	{
		small[i] = rand();
	}
#endif
#ifdef USE_MEDIUM
	for (auto i = 0; i < MEDIUM_SIZE; i++)
	{
		medium[i] = rand();
	}
#endif
#ifdef USE_LARGE
	for (auto i = 0; i < LARGE_SIZE; i++)
	{
		large[i] = rand();
	}
#endif
}

bool checkSort(const int* array, const int& size)
{
	int low = INT_MIN;
	for (auto i = 0; i < size; i++)
	{
		if (array[i] < low)
		{
			return false;
		}
		low = array[i];
	}
	return true;
}

void bubleSort(const int* array, const int& size) {


uint8_t array2[size];
std::cout << array2 << std::endl;

memcpy(array2,array,size);

	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < (i - size); j++)
		{
			if(array2[j] > array2[j+1])
			{
				int tmp = array2[j];
				array2[j] = array2[j+1];
				array2[j+1] = tmp;
			}
		}
	}
}

void insertionSort(const int* array, const int& size) {

}

void mergeSort(const int* array, const int& size) {

}

void heapSort(const int* array, const int& size) {

}

void startBubleSort() {
#ifdef USE_SMALL
	bubleSort(&small[0], SMALL_SIZE);
#endif // USE_SMALL
#ifdef USE_MEDIUM
	bubleSort(&medium[0], MEDIUM_SIZE);
#endif // USE_MEDIUM
#ifdef USE_LARGE
	bubleSort(&large[0], LARGE_SIZE);
#endif // USE_LARGE
}

void startInsertionSort() {
#ifdef USE_SMALL
	insertionSort(&small[0], SMALL_SIZE);
#endif // USE_SMALL
#ifdef USE_MEDIUM
	insertionSort(&medium[0], MEDIUM_SIZE);
#endif // USE_MEDIUM
#ifdef USE_LARGE
	insertionSort(&large[0], LARGE_SIZE);
#endif // USE_LARGE
}

void startMergeSort() {
#ifdef USE_SMALL
	mergeSort(&small[0], SMALL_SIZE);
#endif // USE_SMALL
#ifdef USE_MEDIUM
	mergeSort(&medium[0], MEDIUM_SIZE);
#endif // USE_MEDIUM
#ifdef USE_LARGE
	mergeSort(&large[0], LARGE_SIZE);
#endif // USE_LARGE
}

void startHeapSort() {
#ifdef USE_SMALL
	heapSort(&small[0], SMALL_SIZE);
#endif // USE_SMALL
#ifdef USE_MEDIUM
	heapSort(&medium[0], MEDIUM_SIZE);
#endif // USE_MEDIUM
#ifdef USE_LARGE
	heapSort(&large[0], LARGE_SIZE);
#endif // USE_LARGE
}

int main()
{
	init();
	auto startInit = std::chrono::system_clock::now();
	
	startBubleSort();
	//startInsertionSort();
	//startMergeSort();
	//startHeapSort();

	auto endInit = std::chrono::system_clock::now();

	std::chrono::duration<double> elapsed_seconds = endInit - startInit;

	std::cout << "finished computation elapsed time: " << elapsed_seconds.count() << "s" << std::endl;
#ifdef USE_SMALL
	std::cout << "Small is sorted: " << (checkSort(&small[0], SMALL_SIZE) ? "true" : "false") << std::endl;
#endif // USE_SMALL
#ifdef USE_MEDIUM
	std::cout << "Medium is sorted: " << (checkSort(&medium[0], MEDIUM_SIZE) ? "true" : "false") << std::endl;
#endif // USE_MEDIUM
#ifdef USE_LARGE
	std::cout << "Large is Sorted: " << (checkSort(&large[0], LARGE_SIZE) ? "true" : "false") << std::endl;
#endif // USE_LARGE
	
	int in;
	std::cin >> in;
    return 0;
}

