#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm> 
#include <chrono> 
using namespace std;
using namespace std::chrono;

/* Function prototypes */
int stoogeSort(int array[], int start, int end);
void fillArray(int array[], int n, const int MAX_VALUE, const int MIN_VALUE);
void printArray(int array[], int n);

int main() {
	// Constants
	const int MIN_VALUE = 0;	// Minimum value
	const int MAX_VALUE = 10000;	// Maximum value
	int array[10];
	int n = sizeof(array) / sizeof(array[0]);	// Size of array.
												// Get the system time.
	unsigned seed = time(0);

	// Seed the random number generator.
	srand(seed);
	cout << "Number of elements generated: " << n << endl;	// Number of elements in array.
	fillArray(array, n, MAX_VALUE, MIN_VALUE);

	// https://www.geeksforgeeks.org/measure-execution-time-function-cpp/
	// Get starting timepoint 
	auto start = high_resolution_clock::now();

	// Call Merge Sort procedure.
	stoogeSort(array, 0, n - 1);

	// Print the sorted array.
	printArray(array, n - 1);

	// Get ending timepoint 
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
	return 0;
}

int stoogeSort(int array[], int start, int end) {
	if (start >= end) {
		return 0;
	}
	int n = end - start + 1;
	if (n == 2 && array[start] > array[end]) {
		int temp = array[end];
		array[end] = array[start];
		array[start] = temp;
	}
	else if (n > 2) {
		//int m = floor(n / 3);
		//int m = ceil(n / 3);
		int m = (end - start + 1) / 3;
		stoogeSort(array, start, end - m);
		stoogeSort(array, start + m, end);
		stoogeSort(array, start, end - m);
	}
	return 0;
}

void printArray(int array[], int n) {
	for (int i = 0; i < n; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

void fillArray(int array[], int n, const int MAX_VALUE, const int MIN_VALUE) {
	for (int i = 0; i < n; i++) {
		array[i] = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
	}
}