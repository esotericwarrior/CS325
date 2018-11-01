#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm> 
#include <chrono> 

using namespace std;
using namespace std::chrono;

// Function Prototypes
void printArray(int array[], int length);
void merge(int arr[], int start, int middle, int end);
void mergeSort(int array[], int start, int end);
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

	// Call Merge Sort procedure.
	mergeSort(array, 0, n - 1);

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

void merge(int arr[], int start, int middle, int end) {
	int i = 0;
	int j = 0;
	int k = start;
	// Create two lists to store the halved array.
	int list1 = (middle - start) + 1;
	int list2 = (end - middle);
	// We use a vector here because the list sizes aren't known until runtime.
	// Therefore, an array declaration won't work here.
	vector<int> left(list1), right(list2);
	for (int i = 0; i < list1; i++) {
		left[i] = arr[start + i];
	}
	for (int j = 0; j < list2; j++) {
		right[j] = arr[middle + 1 + j];
	}
	// Continue sorting while there are elements that need to be sorted.
	while (i < list1 && j < list2) {
		// If the head of the first list is smaller than or equal to the head of the right:
		if (left[i] <= right[j]) {
			// Place the smaller element first.
			arr[k] = left[i];
			i++;
		}
		// Else the head of the second list is smaller,
		else {
			// So place that element first instead.
			arr[k] = right[j];
			j++;
		}
		k++;
	}
	while (i < list1) {
		arr[k] = left[i];
		i++;
		k++;
	}
	while (j < list2) {
		arr[k] = right[j];
		j++;
		k++;
	}
}

// Recursive Merge Sort Implementation
void mergeSort(int array[], int start, int end)
{
	// Base case
	if (start >= end) {
		return;
	}
	// Step 1: Divide the array in half to find the middle index.
	int middle = start + (end - start) / 2;
	// Create temporary arrays for the left and the right.

	// Step 2: Recursively sort each half. 
	// Recursive call on the first half.
	mergeSort(array, start, middle);
	// Recursive call on the second half.
	mergeSort(array, middle + 1, end);
	//Step 3: Call the merge subroutine.
	merge(array, start, middle, end);
}

void fillArray(int array[], int n, const int MAX_VALUE, const int MIN_VALUE) {
	for (int i = 0; i < n; i++) {
		array[i] = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
	}
}