#include <iostream>
#include <chrono>
#include <thread>

int main()
{
    int x = 0;
    int y = 1;

    while (x < y)
    {
        x++;
        std::cout << "x = " << x << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        y++;
        std::cout << "y = " << y << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        if (y == 10)
            break;
    }
    return 0;
}
