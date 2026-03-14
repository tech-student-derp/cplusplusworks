#include <iostream>
#include <limits>
#include <string>
using namespace std;

int main() {
    double studentGrades, average;
    double overall = 0;

    double high = -numeric_limits<double>::infinity();
    double low = numeric_limits<double>::infinity();

    int numberStudents;
    string remarks;

    cout << "Enter number of students: ";
    cin >> numberStudents;

    for (int i = 1; i <= numberStudents; i++) {
        cout << "Enter grade of student " << i << ": ";
        cin >> studentGrades;

        if (studentGrades < 50 || studentGrades > 100) {
            cout << "Invalid grade numbers";
            return 0;
        }

        overall += studentGrades;
        average = overall / numberStudents;

        if (studentGrades > high) {
            high = studentGrades;
        }
        if (studentGrades < low) {
            low = studentGrades;
        }
    }

    cout << "\nTotal: " << overall << endl;
    cout << "\nAverage: " << average << endl;
    cout << "\nHighest: " << high << endl;
    cout << "\nLowest: " << low << endl;

    if (average >= 90) {
        remarks = "Excellent";
    } else if (average >= 85) {
        remarks = "Good";
    } else if (average >= 75) {
        remarks = "Needs Improvement but okay";
    } else {
        remarks = "Failed";
    }

    cout << "\nRemarks: " << remarks;

    return 0;
}
