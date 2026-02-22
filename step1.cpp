#include <iostream>
#include <vector>
#include <limits>
using namespace std;

// Function to safely take a number between minVal and maxVal
double getValidatedMark(int subjectNo, double minVal = 0, double maxVal = 100) {
    double mark;
    while (true) {
        cout << "Enter marks for subject " << subjectNo << " (" << minVal << "-" << maxVal << "): ";
        cin >> mark;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
        } else if (mark < minVal || mark > maxVal) {
            cout << "Marks must be between " << minVal << " and " << maxVal << ".\n";
        } else {
            return mark;
        }
    }
}

int main() {
    string name;
    int subjects;

    cout << "===== Student Grade Calculator =====\n";

    cout << "Enter student name: ";
    getline(cin, name);

    cout << "Enter number of subjects: ";
    while (!(cin >> subjects) || subjects <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a valid positive number: ";
    }

    vector<double> marks(subjects);
    double total = 0;

    for (int i = 0; i < subjects; i++) {
        marks[i] = getValidatedMark(i + 1);
        total += marks[i];
    }

    double average = total / subjects;
    char grade;

    if (average >= 90) grade = 'A';
    else if (average >= 80) grade = 'B';
    else if (average >= 70) grade = 'C';
    else if (average >= 60) grade = 'D';
    else grade = 'F';

    cout << "\n===== Result =====\n";
    cout << "Student: " << name << "\n";
    cout << "Total Marks: " << total << "\n";
    cout << "Average: " << average << "\n";
    cout << "Grade: " << grade << "\n";

    return 0;
}
