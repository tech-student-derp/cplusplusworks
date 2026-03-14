/* Joshua P. Flores
   Archilles H. Espiritu */
#include <iostream>
using namespace std;
int main() {
    int x;
    cout << "Enter size of square: ";
    cin >> x;
    for (int i = 1; i <= x; i++) {
        for (int k = 1; k <= x; k++) {
            cout << "*";
        }
        cout << "\n";
    }
    return 0;
}
