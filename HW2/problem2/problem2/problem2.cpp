#include <iostream>
#include <vector>
using namespace std;

/* Function prototype */
int ternarySearch(int array[], int l, int h, int x);

int main() {
	int x;
	int n = 9;
	int array[9] = { 1, 2, 3, 4, 5, 6, 7, 8 ,9 };
	cout << "Enter element to search: ";
	cin >> x;
	int index = ternarySearch(array, 0, n - 1, x);
	if (index == -1)
		cout << "Element is not present in the array !  ";
	else
		cout << "Element is present in the array at index " << index << endl;
	return 0;
}

int ternarySearch(int array[], int l, int h, int x) {
	int middle1, middle2;
	if (l <= h) {
		middle1 = l + (h - l) / 3;
		middle2 = h - (h - l) / 3;
	}
	if (x == array[middle1]) {
		return middle1;
	}
	if (x == array[middle2]) {
		return middle2;
	}
	if (x < array[middle1]) {
		return ternarySearch(array, l, middle1 - 1, x);
	}
	else {
		return ternarySearch(array, middle1 + 1, middle2 - 1, x);
	}
	return -1;
}