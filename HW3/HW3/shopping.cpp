/****************************************************
* shopping.cpp                                      *
* This program solves the 0-1 knapsack problem from *
* an input file that contains T test cases, N number*
* of items, P prices, W weight, F family members and*
* the maximum weight each family member can carry   *
****************************************************/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

/* Function Prototypes */
int knapSack(int P[], int W[], int itemChosen[], int M, int N);
void solve(int P[], int W[], int M[], int N, int F, ofstream & output);

int main() {
	ifstream input("shopping.txt");
	if (input.fail()) {
		cout << "ERROR: Unable to open file." << endl;
		return 0;
	}
	ofstream output("shopping.out");
    int T;  // Number of test cases.
    int i, j;   // Loop control variables.
    input >> T;
    int caseCount = 1;	// Test Case counter.
    /* Outer loop for test cases. */
    for (i = 0; i < T; i++) {
		/*Display Test Case Count in output file */
		output << "Test Case " << caseCount << endl;
		/* Counter for Test Cases */
		caseCount++;
        int N; // Number of items.
        input >> N;
        /* Create two arrays to store P(prices) and W(weights) for each test case.*/
        int P[N], W[N]; // Each array is of size N, specified in the input file.
        /* Loop to fill each array with the input data. */
        for (j = 0; j < N; j++) {
            input >> P[j]; // Fill in the prices (0...n)
            input >> W[j]; // Fill in the weights (0...n)
        }
        /* The next number is for family members.*/
        int F; // Variable to hold the number of family members.
        input >> F;
        /* Store the weight capacity of each family member in an array. */
        int M[F]; // array to store the weight capacity for each family member.
        for (j = 0; j < F; j++) {
            input >> M[j]; // fill M[j]
        }
        solve(P, W, M, N, F, output); // write solution for test case into output file
    }
    input.close(); // close input file
    output.close(); // close output file
    return 0;
}

/****************************************************
*                   int knapSack                    *
* Parameters:                                       *
* int P[] array of prices                           *
* int W[] array of range of weights                 *
* int itemChosen[] array to note when an item has   *
* been selected                                     *
* int M that represents the max weight capacity a   *
* family member can carry                           *
* int N the number of items available               *
* Description: This function initializes a 2D array *
* of size N*M to find the optimal solution with a   *
* dynamic programming approach. When an item has    *
* been chosen, it is added to the itemChosen[]      *
* array to be used to display the selected items    *
* later in the program. This function returns the   *
* maximum value result.                             *
****************************************************/
int knapSack(int P[], int W[], int itemChosen[], int M, int N) {
    int K[N + 1][M + 1]; // K[i][w] stores the maximum value obtained considering items from 0 to i, with a maximum weight limit of w
    int B[N + 1][M + 1]; // B[i][w] keeps track of whether item i was included in the calculation of K[i][w]
    int i;  // Variable used to store the last row of the completed matrix.
    int w;  // Variable used to store the last column of completed matrix.
    /* Outer loop to iterate through all items. */
    for (i = 0; i <= N; i++) {
        /* Inner loop to iterate over the range of weights. */
        for (w = 0; w <= M; w++) {
            B[i][w] = 0; // 0 items
            // BASE CASE: If the number of items or maximum weight allowed is zero:
            if (i == 0 || w == 0){
                K[i][w] = 0; // set K[i][w] to 0
            }
            // If the weight of current item is > than the maximum allowed weight:
            else if (W[i - 1] <= w) {
                int k1 = P[i - 1] + K[i - 1][w - W[i - 1]]; // new value if item is included
                int k2 = K[i - 1][w]; // new value if item is excluded
                // Compare items to see which gives more benefit:
                if (k1 > k2) {
                    K[i][w] = k1; // set value to value after including the current item
                    B[i][w] = 1; // mark the current item as taken
                }
                else {
                    K[i][w] = k2; // set the value to value after excluding the current item
                }
            } else
                K[i][w] = K[i - 1][w]; // current item cannot be included
        }
    }
    // Set control variables to begin back-tracking through the completed matrix.
    i = N; // Last row
    w = M; // Last column
    // Begin back-tracking through the matrix to find itemChosen items.
    while (i > 0 && w >= 0) {
         // If the current item was taken:
        if (B[i][w] == 1) {
            itemChosen[i - 1] = 1; // Mark itemChosen to true.
            w -= W[i - 1]; // decrease the weight by the weight of the itemChosen item
            i--; // Move up one row to next item.
        }
        else{
            i--; // Move up one row to next item.
        }
    }
    return K[N][M]; // return K[N][M] as the solution
}
/****************************************************
*                   void solve                      *
* Parameters:                                       *
* int P[] array of prices                           *
* int W[] array of range of weights                 *
* int M that represents the max weight capacity a   *
* family member can carry                           *
* int N the number of items available               *
* int F the number of family members.               *
* ofstream & output the file to print the results.  *
* Description: This function calculates the total   *
* price of all the items selected by each family    *
* member and prints the results to the output file  *
* for each test case. It also uses the itemChosen[] *
* array to write the items each family members takes*
* to come up with the maximum value and price.      *
****************************************************/
void solve(int P[], int W[], int M[], int N, int F, ofstream & output) {
    int total = 0;  // Variable used to store the total of items from all family members.
    int i, j;   // Loop control variables.
    int itemChosen[F][N];
    // Loop to iterate over all family members.
    for (i = 0; i < F; i++) {
        for (j = 0; j < N; j++){
            itemChosen[i][j] = 0;
        }
        total += knapSack(P, W, itemChosen[i], M[i], N); // Solve for the current family member.
    }
    // Print results to the output file.
    output << "Total Price " << total << endl; // Total price of items for all family members.
    output << "Member Items:" << endl;
    // Loop to iterate over the members of the family.
    for (i = 0; i < F; i++) {
        output << i + 1 << ": "; // write member number to the output file
        // Loop to iterate over the items.
        for (j = 0; j < N; j++) {
            // If the current family member has taken the item:
            if (itemChosen[i][j] == 1){
                // Mark that row, denoting that item has been taken, and write to the output file.
                output << j + 1 << " ";
            }
        }
        output << endl; // write new line to seperate next member
    }
}