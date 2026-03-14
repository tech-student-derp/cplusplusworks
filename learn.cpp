#include <iostream>
#include <vector>
#include <limits>

void errorInputText() {std::cout << "Error: Invalid input.\n";}

void negativeInputText() {std::cout << "Error: Negative input is not allowed.\n";}

void clearInput()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void inputRowsNCols(int& rows, int& cols)
{
    std::cout << "Enter number of rows: ";
    while (true)
    {
        std::cout << "\n>> ";
        std::cin >> rows;
        if (std::cin.fail())
        {
            errorInputText();
            clearInput();
        } else if (rows < 0)
        {
            negativeInputText();
            clearInput();
        } else break;
    }
    std::cout << "Enter number of cols: ";
    while (true)
    {
        std::cout << "\n>> ";
        std::cin >> cols;
        if (std::cin.fail())
        {
            errorInputText();
            clearInput();
        } else if (cols < 0)
        {
            negativeInputText();
            clearInput();
        } else break;
    }
}

void fillArrTemp(int& rows, int& cols, std::vector<int>& rowArr, std::vector<int>& colArr)
{
    int rowTemp = 0;
    int colTemp = 0;
    for (int i = 0; i < rows; ++i)
    {
        rowArr.at(i) = rowTemp;
        rowTemp++;
    }
    for (int i = 0; i < cols; ++i)
    {
        colArr.at(i) = colTemp;
        colTemp++;
    }
}

void inputElementsInArr(int& rows, int& cols, std::vector<std::vector<int>>& arr)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            std::cout << "Enter element of arr row " << i << ", column " << j << ": ";
            while (true)
            {
                std::cout << "\n>> ";
                std::cin >> arr.at(i).at(j);
                if (std::cin.fail())
                {
                    errorInputText();
                    clearInput();
                } else break;
            }
        }
    }
}

void displayArr(int& rows, int& cols, std::vector<std::vector<int>>& arr)
{
    std::cout << "\n\n";
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            std::cout << arr.at(i).at(j) << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n\n";
}

void searchNumFunc(int& rows, int& cols, std::vector<std::vector<int>>& arr, int& isFound, std::vector<int>& rowArr, std::vector<int>& colArr)
{
    int searchNum = 0;
    std::cout << "Enter the number you want to search: ";
    while (true)
    {
        std::cout << "\n>> ";
        std::cin >> searchNum;
        if (std::cin.fail())
        {
            errorInputText();
            clearInput();
        } else break;
    }

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (arr.at(i).at(j) == searchNum)
            {
                isFound++;
                std::cout << "Number found at row " << rowArr.at(i) << ", column " << colArr.at(j) << ".\n";
            }
        }
    }
}

void checkAndFind(int& isFound)
{
    if (isFound <= 0)
        std::cout << "No numbers found at all.\n";
}

int main()
{
    char r = 'Y';
    while (toupper(r) == 'Y')
    {
        int rows = 0;
        int cols = 0;

        system("cls");

        inputRowsNCols(rows, cols);

        std::vector<std::vector<int>> arr(rows, std::vector<int>(cols, 0));
        std::vector<int> rowArr(rows);
        std::vector<int> colArr(cols);

        fillArrTemp(rows, cols, rowArr, colArr);

        inputElementsInArr(rows, cols, arr);

        displayArr(rows, cols, arr);

        int isFound = 0;

        searchNumFunc(rows, cols, arr, isFound, rowArr, colArr);

        checkAndFind(isFound);

        std::cout << "Retry again? [y][n]: ";
        std::cin >> r;
    }
    return 0;
}
