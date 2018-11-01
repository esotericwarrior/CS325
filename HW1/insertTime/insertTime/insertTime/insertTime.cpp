#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm> 
#include <chrono> 

using namespace std;
using namespace std::chrono;

// Function prototypes
void printArray(int array[], int length);
void insertionSort(int array[], int length);
void fillArray(int array[], int n, const int MAX_VALUE, const int MIN_VALUE);

int main() {
	// Constants
	const int MIN_VALUE = 0;	// Minimum value
	const int MAX_VALUE = 10000;	// Maximum value
	int array[1000];
	int n = sizeof(array) / sizeof(array[0]);	// Size of array.
	// Get the system time.
	unsigned seed = time(0);
	
	// Seed the random number generator.
	srand(seed);
	cout << "Number of elements generated: " << n << endl;	// Number of elements in array.
	fillArray(array, n, MAX_VALUE, MIN_VALUE);
	//cout << "*********************************" << endl;
	//cout << "*	Unsorted array		*" << endl;
	//cout << "*********************************" << endl;
	//printArray(array, n);
	//cout << endl;

	// https://www.geeksforgeeks.org/measure-execution-time-function-cpp/
	// Get starting timepoint 
	auto start = high_resolution_clock::now();
	
	// Call Insertion Sort procedure.
	//insertionSort(array, 4999);
	insertionSort(array, n);
	
	// Get ending timepoint 
	auto stop = high_resolution_clock::now();

	// Results
	//cout << "*************************************************" << endl;
	//cout << "*	Sorted array with Insertion Sort	*" << endl;
	//cout << "*************************************************" << endl;
	//printArray(array, n);	// Print the sorted array.
	// Get duration. Substart timepoints to  
	// get durarion. To cast it to proper unit 
	// use duration cast method 
	auto duration = duration_cast<microseconds>(stop - start); 
	cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
	return 0;
}

// Function definitions
/* Utility print function to test arrays. */
void printArray(int array[], int length) {
	for (int i = 0; i < length; i++) {
		cout << array[i] << " ";
	}
	cout << "\n";
}

/* Recursive implementation of Insertion Sort */
void insertionSort(int array[], int length) {
	// Base Case
	if (length <= 1) {
		return;
	}
	// Else (length > 1)
	insertionSort(array, length - 1);
	// Insert the last element at correct position in sorted array.
	int x = array[length - 1];
	int j = length - 2;
	// Move elements > key ahead one of current position.
	while (j >= 0 && array[j] > x) {
		array[j + 1] = array[j];
		j--;
	}
	array[j + 1] = x;
}

void fillArray(int array[], int n, const int MAX_VALUE, const int MIN_VALUE) {
	for (int i = 0; i < n; i++) {
		array[i] = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
	}
}