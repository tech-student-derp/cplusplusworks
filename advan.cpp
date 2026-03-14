#include <iostream>

int main()
{
    int arr[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };

    int num = 1;

    for (auto& i : arr)
    {
        for (auto& j : i)
        {
            arr[i][j] = num;
            num++;
        }
    }

    for (auto &i : arr)
    {
        for (auto &j : i)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}
