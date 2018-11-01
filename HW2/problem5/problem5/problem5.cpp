#include <iostream>
#include <fstream>
using namespace std;

/* Function prototypes */
int stoogeSort(int array[], int l, int h);
void printArray(int array[], int n);

int main() {
	//int array[] = { 8, 9, 2, 5, 4, 6, 19 };
	////int array[] = { 2, 1 };
	//int n = sizeof(array) / (sizeof(array[0]));
	//stoogeSort(array, 0, n-1);
	//printArray(array, n);
	ifstream in("data.txt");
	if (in.fail()) {
		cout << "ERROR: Unable to open file." << endl;
		return 0;
	}
	ofstream out("stooge.out");
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
		// Call Merge Sort procedure.
		stoogeSort(array, 0, n - 1);

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
	cout << "Sorted results written to 'stooge.out'" << endl;
	return 0;
}

int stoogeSort(int array[], int l, int h) {
	if (l >= h) {
		return 0;
	}
	int n = h - l + 1;
	if (n == 2 && array[l] > array[h]) {
			//swap(array[l], array[h]);
			int temp = array[h];
			array[h] = array[l];
			array[l] = temp;
	}
	else if (n > 2) {
		//int m = ceil(2 * (n / 3));
		//int m = ceil(2 * (h - l + 1) / 3);
		//int m = floor(n / 3);
		//int m = ceil(n / 3);
		int m = (h - l + 1) / 3;
		//stoogeSort(array, l, m - 1);
		stoogeSort(array, l, h - m);

		//stoogeSort(array, n - m, n - 1);
		stoogeSort(array, l + m, h);

		//stoogeSort(array, l, m - 1);
		stoogeSort(array, l, h - m);

	}
	return 0;
}


void printArray(int array[], int n) {
	for (int i = 0; i < n; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}