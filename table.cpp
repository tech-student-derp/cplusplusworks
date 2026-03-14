#include <iostream>
#include <string>
#include <random>
#include <iomanip>

const int peopleCount = 5;
const int dayColumn = 7;

void table() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> rand1(10, 99999);

    std::string people[peopleCount] = {
        "Jose", "Roberto", "Joaquin", "Felipe", "Carlo"
    };
    std::string days[dayColumn] = {
        "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
    };

    for (int i = 0; i < dayColumn; i++) {
        std::cout << std::setw(10) << days[i];
    }
    std::cout << "\n";
    for (int i = 0; i < peopleCount; i++) {
        std::cout << std::setw(10) << people[i];
        for (int j = 0; j <= peopleCount; j++) {
            int money1 = rand1(gen);
            std::cout << "$" << money1 << ".00" << std::setw(10);
        }
        std::cout << "\n";
    }
}

int main() {
    char retry;
    do {
        table();
        std::cout << "\nRetry? (y/n): ";
        std::cin >> retry;
    } while (retry == 'y');
    return 0;
}
