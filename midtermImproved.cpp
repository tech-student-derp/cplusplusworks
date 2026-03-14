#include <iostream>
#include <string>
#include <limits>
#include <vector>

char r;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void p(const std::vector<int>& v) { for (int c : v) std::cout << static_cast<char>(c); }
void pflush(const std::vector<int>& v) { p(v); std::cout << std::flush; }

// === encoded strings (ASCII arrays) ===
// Main menu
const std::vector<int> S_MENU = {
    91,67,97,108,99,117,108,97,116,111,114,93,32,91,49,93,10, // [Calculator] [1]\n
    91,69,118,101,110,65,110,100,79,100,100,93,32,91,50,93,10, // [EvenAndOdd] [2]\n
    91,69,118,101,110,79,114,79,100,100,93,32,91,51,93,10,     // [EvenOrOdd] [3]\n
    91,71,114,97,100,101,69,110,117,109,70,111,114,76,111,111,112,93,32,91,52,93,10, // [GradeEnumForLoop] [4]\n
    91,71,114,97,100,101,69,110,117,109,87,104,105,108,101,76,111,111,112,93,32,91,53,93,10, // [GradeEnumWhileLoop] [5]\n
    62,62,32 // >>
};

// generic prompts
const std::vector<int> S_BACK = {66,97,99,107,32,116,111,32,77,97,105,110,32,77,101,110,117,63,32,91,32,121,32,47,32,110,32,93,10,62,62,32}; // Back to Main Menu? [ y / n ]\n>>
const std::vector<int> S_RETRY = {82,101,116,114,121,63,32,91,32,121,32,47,32,110,32,93,10,62,62,32}; // Retry? [ y / n ]\n>>
const std::vector<int> S_ERR_INV = {91,69,82,82,79,82,93,32,73,110,118,97,108,105,100,32,105,110,112,117,116,46,32,84,114,121,32,97,103,97,105,110,46,10}; // [ERROR] Invalid input. Try again.\n
const std::vector<int> S_ERR_DIV0 = {91,69,82,82,79,82,93,32,68,105,118,105,115,105,111,110,32,98,121,32,48,46,32,84,114,121,32,97,103,97,105,110,46,10}; // [ERROR] Division by 0. Try again.\n
const std::vector<int> S_ERR_OP = {91,69,82,82,79,82,93,32,73,110,118,97,108,105,100,32,111,112,101,114,97,116,111,114,46,32,84,114,121,32,97,103,97,105,110,46,10}; // [ERROR] Invalid operator. Try again.\n

// calculator-specific
const std::vector<int> S_CALC_HDR = {91,67,65,76,67,85,76,65,84,79,82,93,10}; // [CALCULATOR]\n
const std::vector<int> S_ENTER_FIRST = {91,69,110,116,101,114,32,102,105,114,115,116,32,110,117,109,98,101,114,93,32,10,62,62,32}; // [Enter first number] \n>>
const std::vector<int> S_ENTER_SECOND = {91,69,110,116,101,114,32,115,101,99,111,110,100,32,110,117,109,98,101,114,93,32,10,62,62,32}; // [Enter second number] \n>>
const std::vector<int> S_ENTER_OP = {91,69,110,116,101,114,32,111,112,101,114,97,116,105,111,110,93,58,10,91,43,93,32,65,100,100,105,116,105,111,110,10,91,45,93,32,83,117,98,116,114,97,99,116,105,111,110,10,91,42,93,32,77,117,108,116,105,112,108,105,99,97,116,105,111,110,10,91,47,93,32,68,105,118,105,115,105,111,110,10,62,62,32}; // [Enter operation]: ... >>
const std::vector<int> S_RESULT_PRE = {91,82,101,115,117,108,116,93,32}; // [Result]

// even/odd
const std::vector<int> S_EO_HDR = {91,69,86,69,78,32,65,78,68,32,79,68,68,93,10}; // [EVEN AND ODD]\n
const std::vector<int> S_ENTER_RANGE = {91,69,110,116,101,114,32,110,117,109,98,101,114,32,114,97,110,103,101,93,10,62,62,32}; // [Enter number range]\n>>
const std::vector<int> S_LABEL_EVEN = {10,91,69,86,69,78,93,58,32}; // \n[EVEN]:
const std::vector<int> S_LABEL_ODD = {10,10,91,79,68,68,93,58,32};  // \n\n[ODD]:

// even-or-odd counter
const std::vector<int> S_EOO_HDR = {91,69,86,69,78,32,79,82,32,79,68,68,32,67,79,85,78,84,69,82,93,10}; // [EVEN OR ODD COUNTER]\n
const std::vector<int> S_ENTER_COUNT = {91,69,110,116,101,114,32,110,117,109,98,101,114,32,99,111,117,110,116,32,116,111,32,105,110,112,117,116,93,10,62,62,32}; // [Enter number count to input]\n>>
const std::vector<int> S_NUM_PREFIX = {91,78,117,109,98,101,114,32}; // [Number
const std::vector<int> S_BRACK_NL = {93,10,62,62,32}; // ]\n>>

// grade enumerators
const std::vector<int> S_GEF_HDR = {91,71,82,65,68,69,32,69,78,85,77,69,82,65,84,79,82,32,85,83,73,78,71,32,70,79,82,32,76,79,79,80,83,93,10}; // [GRADE ENUMERATOR USING FOR LOOPS]\n
const std::vector<int> S_GEW_HDR = {91,71,82,65,68,69,32,69,78,85,77,69,82,65,84,79,82,32,85,83,73,78,71,32,87,72,73,76,69,32,76,79,79,80,93,10}; // [GRADE ENUMERATOR USING WHILE LOOP]\n
const std::vector<int> S_ENTER_SUBJ = {91,69,110,116,101,114,32,110,117,109,98,101,114,32,111,102,32,115,117,98,106,101,99,116,115,93,10,62,62,32}; // [Enter number of subjects]\n>>
const std::vector<int> S_SUBJ_PREFIX = {91,83,117,98,106,101,99,116,32}; // [Subject
const std::vector<int> S_TOTAL = {91,84,111,116,97,108,93,58,32}; // [Total]:
const std::vector<int> S_AVG = {91,65,118,101,114,97,103,101,93,58,32}; // [Average]:
const std::vector<int> S_HIGHEST = {91,72,105,103,104,101,115,116,93,58,32}; // [Highest]:
const std::vector<int> S_LOWEST = {91,76,111,119,101,115,116,93,58,32}; // [Lowest]:
const std::vector<int> S_REMARKS = {91,82,101,109,97,114,107,115,93,58,32,91}; // [Remarks]: [

const std::vector<int> S_NEWLINE = {10};
const std::vector<int> S_PROMPT = {62,62,32}; // >>

// === end encoded strings ===

void calculator() {
    do {
        clearScreen();
        double num1 = 0, num2 = 0, ans = 0;
        char oper;

        // first number input
        while (true) {
            p(S_CALC_HDR);
            p(S_ENTER_FIRST);
            if (!(std::cin >> num1)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                p(S_ERR_INV);
                continue;
            }
            break;
        }

        // second number input
        while (true) {
            p(S_ENTER_SECOND);
            if (!(std::cin >> num2)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                p(S_ERR_INV);
                continue;
            }
            if (num2 == 0) {
                p(S_ERR_DIV0);
                continue;
            }
            break;
        }

        // operator input
        while (true) {
            p(S_ENTER_OP);
            if (!(std::cin >> oper)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                p(S_ERR_OP);
                continue;
            }
            if (oper != '+' && oper != '-' && oper != '*' && oper != '/') {
                p(S_ERR_OP);
                continue;
            }
            break;
        }

        switch (oper) {
        case '+': ans = num1 + num2; break;
        case '-': ans = num1 - num2; break;
        case '*': ans = num1 * num2; break;
        case '/': ans = num1 / num2; break;
        }

        p(S_RESULT_PRE);
        std::cout << num1 << " " << oper << " " << num2 << " = " << ans;
        p(S_NEWLINE);
        p(S_RETRY);
        std::cin >> r;
    } while (r == 'y');
}

void evenandodd() {
    do {
        clearScreen();
        int num = 0;

        while (true) {
            p(S_EO_HDR);
            p(S_ENTER_RANGE);
            if (!(std::cin >> num)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                p(S_ERR_INV);
                continue;
            }
            break;
        }

        p(S_LABEL_EVEN);
        for (int i = 0; i <= num; ++i) if (i % 2 == 0) std::cout << " [" << i << "] ";
        p(S_LABEL_ODD);
        for (int i = 0; i <= num; ++i) if (i % 2 == 1) std::cout << " [" << i << "] ";
        p(S_NEWLINE);
        p(S_RETRY);
        std::cin >> r;
    } while (r == 'y');
}

void evenorodd() {
    do {
        clearScreen();
        int num = 0, numinput = 0, even = 0, odd = 0;

        while (true) {
            p(S_EOO_HDR);
            p(S_ENTER_COUNT);
            if (!(std::cin >> num)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                p(S_ERR_INV);
                continue;
            }
            break;
        }

        for (int i = 1; i <= num; ++i) {
            while (true) {
                // print "[Number " + i + "]\n>> "
                p(S_NUM_PREFIX);
                std::cout << i;
                p(S_BRACK_NL);
                if (!(std::cin >> numinput)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    p(S_ERR_INV);
                    continue;
                }
                break;
            }
            if (numinput % 2 == 0) ++even; else ++odd;
        }

        p(S_RESULT_PRE);
        std::cout << "[Even count] " << "[" << even << "]\n";
        std::cout << "[Odd count] " << "[" << odd << "]\n";
        p(S_RETRY);
        std::cin >> r;
    } while (r == 'y');
}

void gradeEnumFor() {
    do {
        clearScreen();
        double grades = 0, total = 0, average = 0;
        int gradesCount = 0;
        double highest = std::numeric_limits<double>::lowest();
        double lowest = std::numeric_limits<double>::max();
        std::vector<int> remDummy; // unused placeholder to keep ascii-only goal for visible strings

        while (true) {
            p(S_GEF_HDR);
            p(S_ENTER_SUBJ);
            if (!(std::cin >> gradesCount)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                p(S_ERR_INV);
                continue;
            }
            break;
        }

        for (int i = 1; i <= gradesCount; ++i) {
            while (true) {
                p(S_SUBJ_PREFIX);
                std::cout << i;
                p(S_BRACK_NL);
                if (!(std::cin >> grades)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    p(S_ERR_INV);
                    continue;
                }
                break;
            }
            total += grades;
            if (grades > highest) highest = grades;
            if (grades < lowest) lowest = grades;
        }
        average = total / gradesCount;

        p(S_TOTAL); std::cout << "[" << total << "]\n";
        p(S_AVG); std::cout << "[" << average << "]\n";
        p(S_HIGHEST); std::cout << "[" << highest << "]\n";
        p(S_LOWEST); std::cout << "[" << lowest << "]\n";

        p(S_REMARKS);
        // remarks logic (kept as normal strings to avoid insane array count); still hidden mostly
        if (average >= 90) std::cout << "Excellent";
        else if (average >= 85) std::cout << "Great";
        else if (average >= 75) std::cout << "Good";
        else std::cout << "Needs Improvement";
        std::cout << "]\n";

        p(S_RETRY);
        std::cin >> r;
    } while (r == 'y');
}

void gradeEnumWhile() {
    do {
        clearScreen();
        int counter = 0, i = 1;
        double grades = 0, total = 0, average = 0;
        double highest = std::numeric_limits<double>::lowest();
        double lowest = std::numeric_limits<double>::max();

        while (true) {
            p(S_GEW_HDR);
            p(S_ENTER_SUBJ);
            if (!(std::cin >> counter)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                p(S_ERR_INV);
                continue;
            }
            break;
        }

        while (i <= counter) {
            while (true) {
                p(S_SUBJ_PREFIX);
                std::cout << i;
                p(S_BRACK_NL);
                if (!(std::cin >> grades)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    p(S_ERR_INV);
                    continue;
                }
                break;
            }
            total += grades;
            if (grades > highest) highest = grades;
            if (grades < lowest) lowest = grades;
            ++i;
        }
        average = total / counter;

        p(S_TOTAL); std::cout << "[" << total << "]\n";
        p(S_AVG); std::cout << "[" << average << "]\n";
        p(S_HIGHEST); std::cout << "[" << highest << "]\n";
        p(S_LOWEST); std::cout << "[" << lowest << "]\n";

        p(S_REMARKS);
        if (average >= 90) std::cout << "Excellent";
        else if (average >= 85) std::cout << "Great";
        else if (average >= 75) std::cout << "Good";
        else std::cout << "Needs Improvement";
        std::cout << "]\n";

        p(S_RETRY);
        std::cin >> r;
    } while (r == 'y');
}

int main() {
    do {
        clearScreen();
        int choice = 0;
        while (true) {
            p(S_MENU);
            if (!(std::cin >> choice)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                p(S_ERR_INV);
                continue;
            }
            break;
        }

        r = 'y';
        switch (choice) {
        case 1: calculator(); break;
        case 2: evenandodd(); break;
        case 3: evenorodd(); break;
        case 4: gradeEnumFor(); break;
        case 5: gradeEnumWhile(); break;
        default: p(S_ERR_INV); break;
        }

        // back to main?
        p(S_BACK);
        std::cin >> r;
    } while (r == 'y');

    return 0;
}
