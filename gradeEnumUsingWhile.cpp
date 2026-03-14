#include <iostream>
#include <limits>
#include <string>

int numGrades;

void askInput() {
    std::cout << "How many grades do you want to input? \n>> ";
    std::cin >> numGrades;
}

void enumerate() {
        double grades, total = 0, average;
        double highest = std::numeric_limits<double>::lowest();
        double lowest = std::numeric_limits<double>::max();
        int i = 1;

        std::string remarks[] = {
            "Excellent", "Great", "Good", "Needs Improvement"
        };

        askInput();

        while (i <= numGrades) {
            std::cout << "Enter grade " << i << " >> ";
            std::cin >> grades;

            total += grades;

            if (grades > highest) highest = grades;
            if (grades < lowest) lowest = grades;

            ++i;
        }
        average = total / numGrades;

        std::cout << "Total: " << total;
        std::cout << "\nAverage: " << average;
        std::cout << "\nHighest: " << highest;
        std::cout << "\nLowest: " << lowest;
        std::cout << "\nRemarks: ";

        if (average >= 90) {
            std::cout << remarks[0];
        } else if (average >= 85) {
            std::cout << remarks[1];
        } else if (average >= 75) {
            std::cout << remarks[2];
        } else {
            std::cout << remarks[3];
        }
}

int main() {
    char retry;
    do {
        enumerate();
        std::cout << "\nRetry? [y/n] \n>> ";
        std::cin >> retry;
    } while (retry == 'y');
    return 0;
}
