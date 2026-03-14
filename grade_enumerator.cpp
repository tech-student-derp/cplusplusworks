// Joshua P. Flores ACT AD 1B
#include <iostream>
#include <limits>
using namespace std;
int main() {
    int n, grade;
    cout << "Enter number of students: ";
    cin >> n;
    int highest = numeric_limits<int>::min();
    int lowest  = numeric_limits<int>::max();
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cout << "Enter grade of student " << i << ": ";
        cin >> grade;
        sum += grade;
        if (grade > highest) highest = grade;
        if (grade < lowest)  lowest  = grade;
    }
    double average = static_cast<double>(sum) / n;
    cout << "Average: " << average << "\n";
    cout << "Highest: " << highest << "\n";
    cout << "Lowest: " << lowest << "\n";
    if (average >= 90) cout << "Remark: Excellent\n";
    else if (average >= 75) cout << "Remark: Good\n";
    else cout << "Remark: Needs Improvement\n";
    return 0;
}
