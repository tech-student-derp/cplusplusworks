#include <iostream>
using namespace std;

int main() {
    int num, rem;
    cout << "Enter number: ";
    cin >> num;
    rem = num % 2;

    switch (rem) {
    case 0:
        cout << num << " is an even number!" << endl;
        break;
    case 1:
        cout << num << " is an odd number!" << endl;
        break;
    default:
        cout << "Invalid number, must be an integer number." << endl;
    }
    return 0;
}
