#include <iostream>
#include <chrono>
#include <thread>

int main() {
    std::cout << "\033[?25l";
    for (int i = 1; i <= 31; ++i) {
        std::cout << "\r";

        if (i % 2 == 0)
            std::cout << "[WARNING!]";
        else
            std::cout << "          ";
        std::flush(std::cout);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "\raight thats it          \n\033[?25h";
    return 0;
}
