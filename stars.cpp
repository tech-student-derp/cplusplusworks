#include <iostream>
using namespace std;
int main() {
    int stars;
    cout << "Enter number of stars: ";
    cin >> stars;
    for (int i = 1; i <= stars; i++) {
        cout << "*";
    }
    cout << "\n";
    return 0;
}
