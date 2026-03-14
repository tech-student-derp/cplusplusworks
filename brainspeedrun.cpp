#include <iostream>
#include <vector>
#include <limits>
#include <chrono>
#include <thread>

void inputCounts(int& rows, int& columns)
{
    while (true)
    {
        system("cls");
        std::cout << "Enter rows:\n>> ";
        std::cin >> rows;
        if (std::cin.fail() || rows <= 0)
        {
            system("cls");
            std::cout << "\bInvalid input. Try again.\b";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::this_thread::sleep_for(std::chrono::seconds(1));
            continue;
        } else
            break;
    }
    while (true)
    {
        system("cls");
        std::cout << "Enter columns:\n>> ";
        std::cin >> columns;
        if (std::cin.fail() || columns <= 0)
        {
            system("cls");
            std::cout << "\bInvalid input. Try again.\b";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::this_thread::sleep_for(std::chrono::seconds(1));
            continue;
        } else
            break;
    }
}

void inputVectors(int& rows, int& columns, std::vector<std::vector<int>>& grid)
{
    for (int i = 0; i < rows; ++i)
    {
        std::cout << "Row " << i+1 << "\n";
        for (int j = 0; j < columns; ++j)
        {
            while (true)
            {
                std::cout << "Col " << j+1 << ": ";
                std::cin >> grid[i][j];
                if (std::cin.fail())
                {
                    system("cls");
                    std::cout << "Invalid input. Try again.";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                    continue;
                } else
                    break;
            }
        }
        std::cout << "\n";
    }
}

void outputVector(int& rows, int& columns, std::vector<std::vector<int>>& grid)
{
    std::cout << "\n";
    for (int i = 0; i < rows*4+1; ++i)
    {
        std::cout << "-";
    }
    std::cout << "\n";
    for (int i = 0; i < rows; ++i)
    {
        std::cout << "| ";
        for (int j = 0; j < columns; ++j)
        {
            std::cout << grid[i][j] << " | ";
        }
        std::cout << "\n";
    }
    for (int i = 0; i < rows*4+1; ++i)
    {
        std::cout << "-";
    }
    std::cout << "\n";
}

void sumAndAverage(int& rows, int& columns, std::vector<std::vector<int>>& grid)
{
    int sum = 0;
    int average = 0;
    int total = grid.size() * grid[0].size();
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            sum += grid[i][j];
        }
    }
    average = sum / total;
    std::cout << "Total: " << sum << "\n";
    std::cout << "Average: " << average << "\n";
}

int main()
{
    char retry = 'Y';
    while (toupper(retry) == 'Y')
    {
        int columns = 0;
        int rows = 0;
        inputCounts(rows, columns);
        std::vector<std::vector<int>> grid(rows, std::vector<int>(columns));
        inputVectors(rows, columns, grid);
        outputVector(rows, columns, grid);
        sumAndAverage(rows, columns, grid);
        std::cout << "Try again? (Y/n): ";
        std::cin >> retry;
    }
    return 0;
}
