//#include <iostream>
//#include <algorithm>
//#include <fstream>
//#include <vector>
//
//using namespace std;
//
//class Activity {
//public:
//	Activity(int number, int startTime, int finishTime);
//	Activity();	// Default constructor.
//	~Activity() {}	// Destructor.
//	void setNumber(int activityNumber) { number = activityNumber; }
//	void setStartTime(int startTime) { start = startTime; }
//	void setFinishTime(int finishTime) { finish = finishTime; }
//	int getNumber() const { return number; }
//	int getStartTime() const { return start; }
//	int getFinishTime() const { return finish; }
//	void print() const;
//
//private:
//	int number;	// Activity number.
//	int start;	// Start time.
//	int finish;	// Finish time.
//};
//
//int main() {
//	vector<Activity> activity;
//	int numActivities;	// Number of activities in the set.
//	int N;	// Activity number.
//	int S;	// Start time.
//	int F;	// Finish time.
//	//Activity *a1;
//	/* Open the inpute file: */
//	ifstream file("test.txt");
//	if (file.fail()) {	// If unable to open:
//		cout << "ERROR: Unable to open file." << endl;	// Display error message.
//		return 0;	// Exit
//	}
//
//	file >> numActivities;	// Read number of activities from the input file.
//	cout << "Before sorting" << endl;
//	for (int i = 0; i < numActivities; i++) {
//		file >> N;	// Read activity number from file.
//		file >> S;	// Read start time from file.
//		file >> F;	// Read finish time from file.
//		activity.push_back(Activity(N, S, F));
//	}
//	// Now setup an iterator loop through the vector.
//	vector<Activity>::iterator it;
//	for (it = activity.begin(); it != activity.end(); it++) {
//		// For each activity, print its info:
//		it->print();
//	}
//	cout << endl;
//
//
//	// Ascending
//	//sort(activity.begin(), activity.end());
//	//for (unsigned int i = 0; i < activity.size(); i++) {
//	//	activity.at(i).print();
//	//}
//
//	// Descending
//	sort(activity.rbegin(), activity.rend());
//	for (unsigned int i = 0; i < activity.size(); i++) {
//		activity.at(i).print();
//	}
//	
//	int selected = 0;	// Set selected number of activities to 0.
//	// Create a new array to store results.
//	vector<int> sorted;	// Vector of integers because all we need is the activity number.
//	// Put first value in results vector.
//	sorted.push_back(activity[0].getNumber());
//
//	selected++;
//
//	//// Verify that it worked.
//	//for (int i = 0; i < 1; i++) {
//	//	cout << "\nBefore" << endl;
//	//	cout << "Number of activities selected: " << selected << endl;
//	//	cout << "Activities: " << sorted[i] << endl;
//	//	i++;
//	//}
//	int i = 0;
//	int j = 1;
//	//for (i; i < numActivities; ++i) {
//	for (int k = 0; k < numActivities; k++) {
//
//		if (activity[j].getFinishTime() <= activity[i].getStartTime()) {
//			sorted.push_back(activity[j].getNumber());
//			i = j;
//			//j++;
//			selected++;
//		}
//		//else if (activity[j].getFinishTime() > activity[i].getStartTime()) {
//		//	// Can't include, so update j.
//		//	j++;
//		//}
//		else {
//			j = j + 1;
//		}
//
//	}
//	// Ascending
//	sort(sorted.begin(), sorted.end());
//	//for (unsigned int i = 0; i < activity.size(); i++) {
//	//	activity.at(i).print();
//	//}
//	cout << "Number of activities selected = " << selected << endl;
//	cout << "Activities: ";
//	for (int i = 0; i < sorted.size(); i++) {
//		cout << " " << sorted[i];
//	}
//	cout << endl;
//	return 0;
//}
//
//Activity::Activity(int number, int startTime, int finishTime) {
//	this->number = number;
//	this->start = startTime;
//	this->finish = finishTime;
//}
//
//Activity::Activity() {
//	number = 0;
//	start = 0;
//	finish = 0;
//}
//
//void Activity::print() const {
//	cout << this->number << " " << this->start << " " << this->finish << "\n";
//}
//
//bool operator<(const Activity &s1, const Activity &s2) {
//	return s1.getStartTime() < s2.getStartTime();
//}