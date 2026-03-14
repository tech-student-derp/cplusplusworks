#include <iostream>
#include <limits>

int main() {
    int num, ave;
    int sum = 0;
    int large = std::numeric_limits<int>::min();
    int small = std::numeric_limits<int>::max();
    std::cout << "Enter 5 numbers: ";
    for (int i = 1; i <= 5; i++) {
        std::cin >> num;
        sum += num;
        ave = sum / 5;
        if (num > large) {
            large = num;
        }
        if (num < small) {
            small = num;
        }
    }
    std::cout << "Sum: " << sum;
    std::cout << "\nAverage: " << ave;
    std::cout << "\nLargest: " << large;
    std::cout << "\nSmallest: " << small;
    return 0;
}
