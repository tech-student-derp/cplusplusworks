#include <iostream>
using namespace std;
int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "Even numbers: ";
    for (int i = 0; i <= num; i++) {
        if (i % 2 == 0) cout << i << " ";
    }
    cout << "\nOdd number: ";
    for (int i = 0; i <= num; i++) {
        if (i % 2 == 1) cout << i << " ";
    }
    return 0;
}
