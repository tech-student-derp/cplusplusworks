#include <iostream>

int main() {
    int x, y;
    int even = 0, odd = 0;
    std::cout << "Enter how many numbers: ";
    std::cin >> x;
    for (int i = 1; i <= x; i++) {
        std::cout << "Enter numbers: ";
        std::cin >> y;
        if (y % 2 == 0) {
            even++;
        } else {
            odd++;
        }
    }
    std::cout << "Even: " << even << "\n";
    std::cout << "Odd: " << odd;
    return 0;
}
