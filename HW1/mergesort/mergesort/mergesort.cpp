#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Utility function
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
	while (i < list1 && j < list2){
		// If the head of the first list is smaller than or equal to the head of the right:
		if (left[i] <= right[j]){
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

int main() {

	int array[10] = { 2,5,6,4,7,2,8,3,9,10 };
	//int iArray[] = { 4, 19, 2, 5, 11 };
	int numElements = sizeof(array) / sizeof(array[0]);
	cout << "Number of elements in the array: " << numElements << endl;
	cout << "Array to be sorted: " << endl;
	printArray(array, numElements);
	cout << "Array after being sorted: " << endl;
	//mergeSort(array, 0, 9);
	mergeSort(array, 0, numElements - 1);
	//Print the sorted array
	//printArray(array, 10);
	printArray(array, numElements);

	cout << "Merge Sort Implementation" << endl;
	//ifstream in("data.txt");
	//if (in.fail()) {
	//	cout << "ERROR: Unable to open file." << endl;
	//	return 0;
	//}
	//ofstream out("merge.out");
	//int n;
	//// reading size
	//while (in >> n) {

	//	// Create an array based on length.
	//	int *array = new int[n];
	//	// Read each element.
	//	int j = 0;
	//	while (j < n) {
	//		in >> array[j];
	//		j++;
	//	}
	//	cout << "Number of elements to be sorted: " << n;
	//	cout << endl;
	//	cout << "Array to be sorted: ";
	//	printArray(array, n);
	//	cout << endl;
	//	// Call Merge Sort procedure.
	//	mergeSort(array, 0, n - 1);

	//	// Write the results to the file.
	//	for (int i = 0; i < n; i++) {
	//		out << array[i] << " ";
	//	}
	//	out << endl;
	//	printArray(array, n);
	//	cout << endl;
	//}
	//in.close();
	//out.close();
	//cout << "Sorted results written to 'merge.out'" << endl;
	return 0;
}