#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <windows.h>

void typewriter(std::string text, int typeDelay = 120, int eraseDelay = 60, int waitDelay = 1000)
{
    for (char c : text)
    {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(typeDelay));
        Beep(1000, 1);
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(waitDelay));

    for (int i = text.size() - 1; i >= 0; --i)
    {
        std::cout << "\b \b" << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(eraseDelay));
        Beep(100, 1);
    }
}

int main()
{
    std::vector<std::string> lines;

    lines.push_back("Hello human...");
    lines.push_back("I'd like to know your name...");
    lines.push_back("What is your name? >> ");

    for (const auto &line : lines)
    {
        typewriter(line);
    }
    return 0;
}
