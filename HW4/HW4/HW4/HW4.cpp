#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

class Activity {
public:
	Activity(int number, int startTime, int finishTime);
	Activity();	// Default constructor.
	~Activity() {}	// Destructor.
	void setNumber(int activityNumber) { number = activityNumber; }
	void setStartTime(int startTime) { start = startTime; }
	void setFinishTime(int finishTime) { finish = finishTime; }
	int getNumber() const { return number; }
	int getStartTime() const { return start; }
	int getFinishTime() const { return finish; }
	void print() const;

private:
	int number;	// Activity number.
	int start;	// Start time.
	int finish;	// Finish time.
};

int main() {
	/* Open the inpute file: */
	ifstream file("act.txt");
	if (file.fail()) {	// If unable to open:
		cout << "ERROR: Unable to open file." << endl;	// Display error message.
		return 0;	// Exit
	}
	while (!file.eof()) {
		vector<Activity> activity;
		int numActivities;	// Number of activities in the set.
		int N;	// Activity number.
		int S;	// Start time.
		int F;	// Finish time.
		file >> numActivities;	// Read number of activities from the input file.
		for (int i = 0; i < numActivities; i++) {
			file >> N;	// Read activity number from file.
			file >> S;	// Read start time from file.
			file >> F;	// Read finish time from file.
			activity.push_back(Activity(N, S, F));
		}
		cout << endl;
		// Sort vector in descending order.
		sort(activity.rbegin(), activity.rend());
		int selected = 0;	// Set selected number of activities to 0.
							// Create a new array to store results.
		vector<int> sorted;	// Vector of integers because all we need is the activity number.
							// Put first value in results vector.
		sorted.push_back(activity[0].getNumber());
		selected++;	// Increment selected to reflect the first result being placed into the results vector.
					/* Loop Controls */
		int i = 0;
		int j = 1;
		for (int k = 0; k < numActivities; k++) {
			/* If the finish time of the next activity is <= the start time of the current activity: */
			if (activity[j].getFinishTime() <= activity[i].getStartTime()) {
				// Include that activity:
				sorted.push_back(activity[j].getNumber());
				i = j;	// Update i
				selected++;	// Increment selected.
			}
			/* Else, the activity cannot be included in the solution: */
			else {
				// So update j to the next activity.
				j = j + 1;
			}
		}
		// Sort vector in ascending order.
		sort(sorted.begin(), sorted.end());
		/* Display Results */
		cout << "Number of activities selected = " << selected << endl;
		cout << "Activities: ";
		for (int i = 0; i < sorted.size(); i++) {
			cout << " " << sorted[i];
		}
	}
	cout << endl;
	return 0;
}

Activity::Activity(int number, int startTime, int finishTime) {
	this->number = number;
	this->start = startTime;
	this->finish = finishTime;
}

Activity::Activity() {
	number = 0;
	start = 0;
	finish = 0;
}

void Activity::print() const {
	cout << this->number << " " << this->start << " " << this->finish << "\n";
}

bool operator<(const Activity &s1, const Activity &s2) {
	return s1.getStartTime() < s2.getStartTime();
}