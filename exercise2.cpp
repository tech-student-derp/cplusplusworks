#include <iostream>
using namespace std;
int main() {
    int x, y = 0, z = 1;
    cout << "Enter 3 numbers: ";
    for (int i = 1; i <= 3; i++) {
        cin >> x;
        y += x;
        z *= x;
    }
    cout << "Sum: " << y;
    cout << "\nProduct: " << z;
    return 0;
}
