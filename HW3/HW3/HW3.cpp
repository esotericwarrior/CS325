#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int knapsack(int W, vector<int> weight, vector<int> value, int n, int s[]);
int getMax(int x, int y);
void printList(vector<vector<int>> &matrix);
void displayResults(vector<int> maxWeight, vector<int> W, vector<int> prices, int N, int familyMembers, ofstream & out);

int main() {
	ifstream file("test.txt");
	if (file.fail()) {
		cout << "ERROR: Unable to open file." << endl;
		return 0;
	}
	ofstream out("shopping.out");

	int T;	// Number of test cases.
	file >> T;	// Read T from input file.
	//cout << "Number of test cases: " << T << endl;
	int caseCount = 1;	// Test Case counter.
	/* Outer loop for test cases. */
	for (int i = 0; i < T; i++) {
		/*Display Test Case Count */
		cout << "Test Case " << caseCount << endl;
		out << "Test Case " << caseCount << endl;
		/* Counter for Test Cases */
		caseCount++;
		int N;	// Number of items.
		file >> N;	// Read N from input file.
		//cout << "Number of items: " << N << endl;
		vector<int> prices(N), W(N); // Vectors to store P and W.
		for (int j = 0; j < N; j++){
			file >> prices[j]; // fill P[j]
			//cout << "Price: " << prices[j] << " ";
			file >> W[j]; // fill W[j]
			//cout << "Weight: " << W[j] << endl;
		}
		/* Verify that prices are being properly stored in vector. */
		//cout << "Prices in P: ";
		//for (int i = 0; i < prices.size(); i++) {
		//	cout << prices[i] << " ";
		//}
		//cout << endl;
		/* Verify that weights are being properly stored in vector. */
		//cout << "Weight in W: ";
		//for (int i = 0; i < W.size(); i++) {
		//	cout << W[i] << " ";
		//}
		//cout << endl;
		int familyMembers; // Number of family members.
		file >> familyMembers;	// Read familyMembers from input file.
		//cout << "Number of family members: " << familyMembers << endl;
		vector<int> maxWeight(familyMembers);
		for (int j = 0; j < familyMembers; j++) {
			file >> maxWeight[j];	// Fill F[j]
			//cout << "Max weight family member can hold: " << maxWeight[j] << endl;
		}
		/*Display results*/
		displayResults(maxWeight, W, prices, N, familyMembers, out);

	} // Test case loop
	file.close();	// Close the input file.
	out.close();	// Close the output file.
	return 0;
}

int getMax(int x, int y) {
	if (x > y) {
		return x;
	}
	else {
		return y;
	}
}

int knapsack(int W, vector<int> weight, vector<int> value, int n, int s[]) {

	/* matrix[i][w] to be the maximum value that can be attained
	with weight less than or equal to w using items up to i*/
	// Create matrix[n + 1][W + 1] to store values.
	vector<vector<int> > matrix(n + 1, vector<int>(W + 1, 0));
	vector<vector<int> > E(n + 1, vector<int>(W + 1));	// For later use with selected items.
	//for (int jw = 0; jw <= W; jw++) {
	//	matrix[0][jw] = 0;
	//}
	//for (int i = 1; i <= n; i++) {
	//	for (int jw = 0; jw <= W; jw++) {

	//		// A case when the new item is more than the current weight limit
	//		if (weight[i - 1] > jw){
	//			matrix[i][jw] = matrix[i - 1][jw];
	//		}
	//		// A case for weight[i] < jw
	//		else {
	//			matrix[i][jw] = getMax(matrix[i - 1][jw], value[i - 1] + matrix[i - 1][jw - weight[i - 1]]);
	//			s[jw] = i;
	//		}
	//	}
	//}


	/* Outer loop to iterate over all items. */
	for (int i = 0; i <= n; i++) {
		/* Inner loop to iterate over the range of weights. */
		for (int w = 0; w <= W; w++) {
			E[i][w] = 0;	// Set default to item not taken.
			// BASE CASE: If the number of items or maximum weight allowed is zero:
			if (i == 0 || w == 0) {
				// Zero out the first row and column.
				matrix[i][w] = 0; // Set matrix[i][w] to 0.
			}
			// If the weight of current item is > than the maximum allowed weight:
			else if (weight[i - 1] <= w) {
				int k1 = value[i - 1] + matrix[i - 1][w - weight[i - 1]]; // new value if item is included
				int k2 = matrix[i - 1][w]; // new value if item is excluded
				// if including item is more profitable
				if (k1 > k2) {
					matrix[i][w] = k1; // set value to value after including the current item
					E[i][w] = 1; // mark the current item as taken
				}
				else {
					matrix[i][w] = k2; // set the value to value after excluding the current item
				}
			}
			else
				matrix[i][w] = matrix[i - 1][w]; // current item cannot be included
		}
	}
	int i = n; // start from the final item
	int w = W; // set current weight to M for backtracking
	// Begin back-tracking through the matrix to find selected items.
	while (i > 0 && w >= 0) {
		if (E[i][w] == 1) {
			s[i - 1] = 1; // mark selected to true
			w -= weight[i - 1]; // decrease the weight by the weight of the selected item
			i--; // move to next item
		}
		else
			i--; // move to next item
	}


	// Start with the last number in the matrix.
	//int i = n; // Last row.
	//int w = W; // Last column.
	///*We consider the last column of the table and start
	//scanning the entries from bottom to top. If we encounter
	//an entry whose value is not same as the value which is
	//stored in the entry immediately above it, then we will
	//mark the label of row of that entry.*/
	//while (i > 0 && w >= 0) {	// Begin back-tracking
	//	// If the current value doesn't match the row above:
	//	if (matrix[i][w] != matrix[i - 1][w]) {
	//		// Mark this row.
	//			//cout << "Item " << i << " taken" << endl;
	//		i--;	// Move up one row.
	//	}
	//	else {
	//		i--;	// Move up one row.
	//	}
	//}
	return matrix[n][W];
}

void displayResults(vector<int> maxWeight, vector<int> W, vector<int> prices, int N, int familyMembers, ofstream & out) {
	/****************************************************
	*					Display Results					*
	*				Also write to shopping.out.			*
	****************************************************/
	int w;	// Weight capacity of current family member.
	int total = 0;	// Total price of all family members' items.
	for (int i = 0; i < maxWeight.size(); i++) {
		w = maxWeight[i];	// Store current family member's weight capacity.
		int *s = new int[w + 1];	// Array used for each family member's selection.
		total = knapsack(w, W, prices, N, s) + total;	// Add to family total.
	}
	cout << "Total Price " << total << endl;
	out << "Total Price " << total << endl;
	cout << "Member Items" << endl;
	out << "Member Items" << endl;
	//for (int i = 0; i < maxWeight.size(); i++) {
	//	cout << "     " << i + 1 << ":		" << endl;
	//	out << "     " << i + 1 << ":		" << endl;
	//}
	// Loop to iterate over the members of the family.
	for (int i = 0; i < familyMembers; i++) {
		cout << i + 1 << ": ";
		out << i + 1 << ": ";
		// Loop to iterate over the items.
		for (int j = 0; j < N; j++) {
			// If the current family member has taken the item:
			if (s[i][j] == 1) {
				// Print it to the console and output file.
				cout << j + 1 << " ";
				out << j + 1 << " ";
			}
		}
		cout << endl;
		out << endl;
	}
	cout << endl;
	out << endl;
}

/* Utility function for testing. */
void printList(vector<vector<int>> &matrix) {
	// Print the 2D vector.
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++)
			cout << matrix[i][j] << " ";
			cout << endl;
		}
	}