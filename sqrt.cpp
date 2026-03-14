#include <iostream>
using namespace std;

int main() {
    int num, sqrt, rem;
    cout << "Hi user! Please input a number" << endl;
    cout << "\nInput a number: ";
    cin >> num;
    if (!num) {
        cout << "Invalid input.";
        return 0;
    }
    sqrt = num * num;
    cout << "\n\tSqare value of " << num << " is " << sqrt << endl;
    rem = sqrt % 2;
    switch (rem) {
        case 0:
            cout << "\t" << sqrt << " is an EVEN number.";
            break;
        case 1:
            cout << "\t" << sqrt << " is an ODD number.";
            break;
        default:
            cout << "Invalid number.";
     }
     return 0;
}
