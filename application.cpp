#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include <iomanip>

char retry;

int width = 20;
int index;
int padding = (width - USERINPUT[index].length()) / 2;

std::vector<std::string> USER_INPUT[] = {
    "[Enter your name]\n>> ";
    "[Enter your age]\n>> ";
    "[Enter your day of your birth]\n>> ";
    "[Enter your month of your birth]\n>> ";
    "[Enter your year of your birth]\n>> "
};

class User {
    std::string username;
    int age;
    int birthDay, birthMonth, birthYear;

};

void cls() {
    std::cout << "\033[2J\033[1;1H";
}

void info {
    User user;

    index = 0;
    std::cout << std::setw(padding + USER_INPUT[index].length()) << USER_INPUT[index];
    std::cin >> user.username;

    index = 1;
    std::cout << std::setw(padding + USER_INPUT[index].length()) << USER_INPUT[index];
    std::cin >> user.age;

    index = 2;
    std::cout << std::setw(padding + USER_INPUT[index].length()) << USER_INPUT[index];
    std

}
