#include <iostream>

int main()
{
    char retry = 'Y';
    while (toupper(retry) == 'Y')
    {
        int n = 0;
        system("cls");
        while (true)
        {
            std::cout << "Enter n: ";
            std::cin >> n;
            if (std::cin.fail() || n <= 0)
            {
                std::cout << "Invalid input.\n";
                std::cin.clear();
                std::cin.ignore(10000000, '\n');
            } else
                break;
        }
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            while (true)
            {
                std::cout << "Enter arr[" << i << "]: ";
                std::cin >> arr[i];
                if (std::cin.fail())
                {
                    std::cout << "Invalid input.\n";
                    std::cin.clear();
                    std::cin.ignore(10000000, '\n');
                } else
                    break;
            }
        }
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (arr[j] > arr[j+1])
                {
                    int t = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = t;
                }
            }
        }
        std::cout << "[ ";
        for (int a : arr)
        {
            std::cout << a << ", ";
        }
        std::cout << "]\n";
        std::cout << "Try again? (y/n): ";
        std::cin >> retry;
    }
    system("cls");
    return 0;
}
