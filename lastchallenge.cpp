#include <iostream>
#include <limits>
using namespace std;

int main() {
    const int maxnum = 5; // Editable

    int num, average;
    int sum = 0;
    int smallest = numeric_limits<int>::max();
    int largest = numeric_limits<int>::min();
    cout << "Enter " << maxnum << " numbers: ";
    for (int i = 1; i <= maxnum; i++) {
        cin >> num;
        sum += num;
        if (num > largest) largest = num;
        if (num < smallest) smallest = num;
    }
    average = sum / maxnum;
    cout << "Largest: " << largest;
    cout << "\nSmallest: " << smallest;
    cout << "\nSum: " << sum;
    cout << "\nAverage: " << average;
    return 0;
}
