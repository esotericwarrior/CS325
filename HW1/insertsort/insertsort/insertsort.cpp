#include <iostream>
#include <fstream>
using namespace std;

void printArray(int array[], int length) {
	for (int i = 0; i < length; i++) {
		cout << array[i] << " ";
	}
	cout << "\n";
}

/*Recursive implementation of Insertion Sort*/
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

int main()
{
	cout << "Insertion Sort Implementation" << endl;
	ifstream in("data.txt");
	if (in.fail()) {
		cout << "ERROR: Unable to open file." << endl;
		return 0;
	}
	ofstream out("insert.out");
	int n;
	// reading size
	while (in >> n) {

		// Create an array based on length.
		int *array = new int[n];
		// Read each element.
		int j = 0;
		while (j < n) {
			in >> array[j];
			j++;
		}
		cout << "Number of elements to be sorted: " << n;
		cout << endl;
		cout << "Array to be sorted: ";
		printArray(array, n);
		cout << endl;
		// Call Insertion Sort procedure.
		insertionSort(array, n);

		// Write the results to the file.
		for (int i = 0; i < n; i++) {
			out << array[i] << " ";
		}
		out << endl;
		printArray(array, n);
		cout << endl;
	}
	in.close();
	out.close();
	cout << "Sorted results written to 'insert.out'" << endl;
	return 0;
}