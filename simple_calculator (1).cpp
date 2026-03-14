// Joshua P. Flores ACT AD 1B
#include <iostream>
using namespace std;
int main() {
    double x, y, z;
    char ope;
    cout << "Enter first number: ";
    cin >> x;
    cout << "Enter secondd number: ";
    cin >> y;
    cout << "Choose operation: ( +, -, *, / ) ";
    cin >> ope;
    switch (ope) {
        case '+':
            z = x + y;
            break;
        case '-':
            z = x - y;
            break;
        case '*':
            z = x * y;
            break;
        case '/':
            if (y == 0) {
                cout << "Error: Division by zero is not allowed.\n";
                return 0;
            } else {
                z = x / y;
            }
            break;
        default:
            cout << "Invalid Operator.";
    }
    cout << "Result: " << z;
    return 0;
}
