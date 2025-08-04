#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
#include<iomanip>

using namespace std;

unordered_map<string, double> gradePoints = {
	{ "A", 4.0 }, { "A-", 3.7 }, { "B+", 3.3 }, { "B", 3.0 },
	{ "B-", 2.7 }, { "C+", 2.3 }, { "C", 2.0 }, { "D", 1.0 }, { "F", 0.0 }
};

double calculateGPA(const vector<string>& grades, const vector<int>& credits) {
	double totalQualityPoints = 0.0;
	int totalCredits = 0;

	for (size_t i = 0; i < grades.size(); i++) {
		if (gradePoints.find(grades[i]) != gradePoints.end()) {
			totalQualityPoints += gradePoints[grades[i]] * credits[i];
			totalCredits += credits[i];
		}
	}

	return totalCredits == 0 ? 0.0 : totalQualityPoints / totalCredits;
}

int main() {
	double currentCGPA;
	int completedCredits;

	cout << "Enter your current CGPA: ";
	cin >> currentCGPA;
	cout << "Enter total completed credit hours: ";
	cin >> completedCredits;

	int numCourses;
	cout << "\nEnter the number of courses this semester: ";
	cin >> numCourses;

	vector<string> grades(numCourses);
	vector<int> credits(numCourses);

	for (int i = 0; i < numCourses; i++) {
		cout << "Course " << i + 1 << " - Grade: ";
		cin >> grades[i];
		cout << "Course " << i + 1 << " - Credit Hours: ";
		cin >> credits[i];
	}

	double newGPA = calculateGPA(grades, credits);
	int newCredits = 0;
	for (int c : credits) {
		newCredits += c;
	}

	double updatedCGPA = ((currentCGPA * completedCredits) + (newGPA * newCredits)) / (completedCredits + newCredits);

	cout << fixed << setprecision(2);
	cout << "\nGPA for this semester: " << newGPA;
	cout << "\nUpdated CGPA: " << updatedCGPA << endl;

	system("pause");
	return 0;
}
