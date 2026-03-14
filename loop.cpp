#include <iostream>
using namespace std;

int main() {
    double grade, numStudents, average, low, high, overall;

    cout << "Enter the number of students: ";
    cin >> numStudents;

    for (int i = 1; i <= numStudents; i++) {
        cout << "Enter the grade of student " << i << ": ";
        cin >> grade;
    }

    overall = grade * numStudents;

    average = overall / numStudents;

    cout << "Student average:" << average << endl;

    if (average >= 90) {
        cout << "Remarks: Excellent";
    } else if (grade >= 89) {
        cout << "Remarks: Good";
    } else if (grade >= 79) {
        cout << "Remarks: Needs improvement";
    } else {
        cout << "Remarks: Failed";
    }

    return 0;
}
