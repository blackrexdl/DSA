#include <iostream>
using namespace std;
char getGrade(double average) {
    if (average >= 90) return 'A';
    if (average >= 80) return 'B';
    if (average >= 70) return 'C';
    if (average >= 60) return 'D';
    return 'F';
}
// This program calculates the total marks, average, and grade for a student based on their marks in multiple subjects.
int main() {
    string studentName;
    int subjectCount;
    double marks, total = 0;

    cout << "Student Grade Calculator\n";
    cout << "Enter student name: ";
    getline(cin, studentName);

    cout << "Enter number of subjects: ";
    cin >> subjectCount;

    for (int i = 1; i <= subjectCount; i++) {
        cout << "Enter marks for subject " << i << ": ";
        cin >> marks;
        total += marks;
    }

    double average = total / subjectCount;

    cout << "\nResult\n";
    cout << "Student: " << studentName << "\n";
    cout << "Total Marks: " << total << "\n";
    cout << "Average: " << average << "\n";
    cout << "Grade: " << getGrade(average) << "\n";

    return 0;
}
