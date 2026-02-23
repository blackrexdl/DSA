#include <iostream>
using namespace std;
// This program calculates the total marks, average, and grade for a student based on their marks in multiple subjects.
int main() {
    string name;
    int subjects;
    double mark, total = 0;

    cout << "Student Grade Calculator\n";
    cout << "Enter student name: ";
    getline(cin, name);

    cout << "Enter number of subjects: ";
    cin >> subjects;

    for (int i = 1; i <= subjects; i++) {
        cout << "Enter marks for subject " << i << ": ";
        cin >> mark;
        total += mark;
    }

    double average = total / subjects;
    char grade;

    if (average >= 90) grade = 'A';
    else if (average >= 80) grade = 'B';
    else if (average >= 70) grade = 'C';
    else if (average >= 60) grade = 'D';
    else grade = 'F';

    cout << "\nResult\n";
    cout << "Student: " << name << "\n";
    cout << "Total Marks: " << total << "\n";
    cout << "Average: " << average << "\n";
    cout << "Grade: " << grade << "\n";

    return 0;
}
