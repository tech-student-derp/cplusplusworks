#include <iostream>
#include <string>
#include <limits>

// Make a calculator
// Even and odd
// Even or odd counter
// Grade evaluator using for loop
// Grade evaluator using while loop

char retry;

void calculator() {
    do {
        double num1 = 0;
        double num2 = 0;
        double ans = 0;
        char oper;

        std::cout << "[CALCULATOR]\n[Enter first number] \n>> ";
        std::cin >> num1;

        std::cout << "[Enter second number] \n>> ";
        std::cin >> num2;

        std::cout << "[Enter operation]:\n[+] Addition\n[-] Subtraction\n[*] Multiplication\n[/] Division\n>> ";
        std::cin >> oper;

        switch (oper) {
        case '+':
            ans = num1 + num2;
            break;
        case '-':
            ans = num1 - num2;
            break;
        case '*':
            ans = num1 * num2;
            break;
        case '/':
            if (num2 == 0) {
                std::cout << "[ERROR] Please do not use numbers that is divisible by 0. Aborting program.";
                return;
            } else {
                ans = num1 / num2;
            }
            break;
        default:
            std::cout << "[ERROR] Invalid operator. Please try again. Aborting program.";
            return;
        }

        std::cout << "[Result] " << num1 << " " << oper << " " << num2 << " = " << ans;
        std::cout << "\nRetry? [ y / n ]\n>> ";
        std::cin >> retry;
    } while (retry == 'y');
}

void evenandodd() {
    do {
        int num = 0;

        std::cout << "[EVEN AND ODD]\n[Enter number range]\n>> ";
        std::cin >> num;

        std::cout << "\n[EVEN]: ";
        for (int i = 0; i <= num; ++i) {
            if (i % 2 == 0) std::cout << " ["<< i << "] ";
        }

        std::cout << "\n\n[ODD]: ";
        for (int i = 0; i <= num; ++i) {
            if (i % 2 == 1) std::cout << " ["<< i << "] ";
        }

        std::cout << "\nRetry? [ y / n ]\n>> ";
        std::cin >> retry;
    } while (retry == 'y');
}

void evenorodd() {
    do {
        int num = 0;
        int numinput = 0;
        int even = 0;
        int odd = 0;

        std::cout << "[EVEN OR ODD COUNTER]\n[Enter number count to input]\n>> ";
        std::cin >> num;

        for (int i = 1; i <= num; ++i) {
            std::cout << "[Number " << i << "]\n>> ";
            std::cin >> numinput;
            if (numinput % 2 == 0) ++even;
            else ++odd;
        }

        std::cout << "[Even count] " << "[" << even << "]\n";
        std::cout << "[Odd count] " << "[" << odd << "]\n";

        std::cout << "Retry? [ y / n ]\n>> ";
        std::cin >> retry;
    } while (retry == 'y');
}

void gradeEnumFor() {
    do {
        double grades = 0, average = 0, total = 0;
        int gradesCount = 0;
        double highest = std::numeric_limits<double>::lowest();
        double lowest = std::numeric_limits<double>::max();

        std::string remarks[] = {
            "Excellent", "Great", "Good", "Needs Improvement"
        };

        std::cout << "[GRADE ENUMERATOR USING FOR LOOPS]\n[Enter number of subjects]\n>> ";
        std::cin >> gradesCount;

        for (int i = 1; i <= gradesCount; ++i) {
            std::cout << "[Subject " << i << "]\n>> ";
            std::cin >> grades;

            total += grades;

            if (grades > highest) highest = grades;
            if (grades < lowest) lowest = grades;
        }
        average = total / gradesCount;

        std::cout << "[Total]: " << "[" << total << "]\n";
        std::cout << "[Average]: " << "[" << average << "]\n";
        std::cout << "[Highest]: " << "[" << highest << "]\n";
        std::cout << "[Lowest]: " << "[" << lowest << "]\n";
        std::cout << "[Remarks]: " << "[";

        if (average >= 90) {
            std::cout << remarks[0];
        } else if (average >= 85) {
            std::cout << remarks[1];
        } else if (average >= 75) {
            std::cout << remarks[2];
        } else {
            std::cout << remarks[3];
        }

        std::cout << "]";

        std::cout << "\nRetry? [ y / n ]\n>> ";
        std::cin >> retry;
    } while (retry == 'y');
}

void gradeEnumWhile() {
    do {
        int counter = 0;
        int i = 1;
        double grades = 0, total = 0, average = 0;
        double highest = std::numeric_limits<double>::lowest();
        double lowest = std::numeric_limits<double>::max();

        std::string remarks[] = {
            "Excellent", "Great", "Good", "Needs Improvement"
        };

        std::cout << "[GRADE ENUMERATOR USING WHILE LOOP]\n[Enter number of subjects]\n>> ";
        std::cin >> counter;
        while (i <= counter) {
            std::cout << "[Subject " << i << "]\n>> ";
            std::cin >> grades;
            total += grades;

            if (grades > highest) highest = grades;
            if (grades < lowest) lowest = grades;

            ++i;
        }
        average = total / counter;

        std::cout << "[Total] " << "[" << total << "]\n";
        std::cout << "[Average] " << "[" << average << "]\n";
        std::cout << "[Highest] " << "[" << highest << "]\n";
        std::cout << "[Lowest] " << "[" << lowest << "]\n";
        std::cout << "[Remarks] " << "[";

        if (average >= 90) {
            std::cout << remarks[0];
        } else if (average >= 85) {
            std::cout << remarks[1];
        } else if (average >= 75) {
            std::cout << remarks[2];
        } else {
            std::cout << remarks[3];
        }
        std::cout << "]\n";

        std::cout << "Retry? [ y / n ]\n>> ";
        std::cin >> retry;
    } while (retry == 'y');
}

int main() {
    do {
        int choice = 0;
        std::cout << "[Calculator] [1]\n[EvenAndOdd] [2]\n[EvenOrOdd] [3]\n[GradeEnumForLoop] [4]\n[GradeEnumWhileLoop] [5]\n>> ";
        std::cin >> choice;

        retry = 'y';
        switch (choice) {
        case 1:
            calculator();
            break;
        case 2:
            evenandodd();
            break;
        case 3:
            evenorodd();
            break;
        case 4:
            gradeEnumFor();
            break;
        case 5:
            gradeEnumWhile();
        default:
            std::cout << "[ERROR] Invalid input. Try again.";
            break;
        }
        std::cout << "Back to Main Menu? [ y / n ]\n>> ";
        std::cin >> retry;
    } while (retry == 'y');

    return 0;
}
