#include <iostream>

int num;
const int divis = 2; // okay that's understandable
const int zero = 0; // no shit sherlock
const int one = 1; // yea i see that with my bare eyes

void even() {
    for (int i = zero; i <= num; i++) {
        if (i % divis == zero) std::cout << i << " ";
    }
}

void odd() {
    for (int i = zero; i <= num; i++) {
        if (i % divis == one) std::cout << i << " ";
    }
}

int main() {
    char con;
    do {
        std::cout << "Enter number: ";
        std::cin >> num;

        std::cout << "Even numbers: ";
        even();

        std::cout << "\nOdd numbers: ";
        odd();

        std::cout << "\nRetry? (y/n) ";
        std::cin >> con;

    } while (con == 'y');
    return 0;
}
