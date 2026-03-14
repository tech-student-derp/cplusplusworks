/* Joshua P. Flores
   Archilles H. Espiritu */
#include <iostream>
using namespace std;
int main() {
    int x;
    cout << "Enter heigh of triangle: ";
    cin >> x;
    for (int i = 1; i <= x; i++) {
        for (int k = 1; k <= i; k++) {
            cout << "*";
        }
        cout << "\n";
    }
}
