#include <iostream>
#include <vector>
#include <cstdlib>
#include <cctype>

int main(int argc, char* argv[])
{
    int rows = 5, cols = 10;
    std::vector<std::vector<int>> hours(rows, std::vector<int>(cols, 0));
    std::vector<char> letters{'A','B','C','D','E'};

    // auto-rent via command line if args given
    if(argc == 3) // expects: rowcol hours (like B5 3)
    {
        char rowLetter = toupper(argv[1][0]);       // 'B'
        int colNum = argv[1][1] - '0';             // '5' → 5
        int rentHrs = std::atoi(argv[2]);          // "3" → 3

        int rowIndex = rowLetter - 'A';
        int colIndex = colNum - 1;

        if(rowIndex >= 0 && rowIndex < rows && colIndex >= 0 && colIndex < cols)
        {
            hours[rowIndex][colIndex] = rentHrs;
            std::cout << "Auto-rented " << rowLetter << colNum
                      << " for " << rentHrs << "h!\n";
        }
        else std::cout << "Invalid computer selection!\n";

        return 0; // exit after auto-rent
    }

    // fallback: normal interactive menu (your existing code)
    std::cout << "No command line args, falling back to menu...\n";

    return 0;
}
