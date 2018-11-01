#include <iostream>
using namespace std;

// Function prototypes
int iterative(int array[], int n, int max, int min);
int min_max(int array[], int start, int end, int n);


int main() {
	//int array[] = { 5, 2, 6, 4, 1 };
	int array[] = { 4, 7, 9, 0 };
	//int array[] = { 44, 53, 19, 24, 6, 99, 0, 26, 101 };
	//int array[] = { 1 };
	//int array[] = { 1, 2 };
	//int array[] = { 2, 1 };
	int low = 0;
	int high = 0;
	int size = sizeof(array) / sizeof(array[0]);
	min_max(array, 0, size-1, size);
	//iterative(array, size, high, low);

	return 0;
}


int iterative(int array[], int n, int max, int min) {
	// Set max to the maximum and min to the minimum of the array.
	max = min = array[0];
	for (int i = 0; i < n; i++) {
		if (array[i] > max) {
			max = array[i];
		}
		if (array[i] < min) {
			min = array[i];
		}
	}
	cout << "Min: " << min << endl;
	cout << "Max: " << max << endl;
	return (max, min);
}

int min_max(int array[], int start, int end, int n) {
	/*Base Case: When the array only has 1 element, 
	it is both the minimum and maximum value. */
	if (n == 1) {
		int min = array[0];
		int max = array[0];
		cout << "Min: " << min << endl;
		cout << "Max: " << max << endl;
		return (array[0], array[0]);
	}
	else if (n == 2) {
		if (array[0] < array[1]) {
			int max = array[1];
			int min = array[0];
			cout << "Min: " << min << endl;
			cout << "Max: " << max << endl;
			return (array[0], array[1]);
		}
		else {
			int max = array[0];
			int min = array[1];
			cout << "Min: " << min << endl;
			cout << "Max: " << max << endl;
			return (array[1], array[0]);
		}
	}
	else {
		// Create two lists to store the halved array.
		//int list1 = (middle - start) + 1;
		//int list2 = (end - middle);
		cout << "Array size: " << n << endl;
		int middle = start + (end - start) / 2;
		cout << "Middle: " << middle << endl;
	}
	return 0;
}