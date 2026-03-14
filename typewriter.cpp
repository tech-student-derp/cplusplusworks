#include <iostream>
#include <chrono>
#include <thread>
#include <windows.h>

int main()
{
    std::string textA = "Hello World!\n\nToday I will be showing you how to do:\n\nTYPEWRITER EFFECT!\n\n";
    std::string textB = "So for this one, we will be using range-type for loop,\nmaking the typewriter effect possible!";
    std::string textC = "#include <iostream>\n#include <chrono>\n#include <thread>\n\nint main()\n{\n\tstd::string text = \"Hello world!\";\n\tfor (char c : text)\n\t{\n\t\tstd::cout << c << std::flush;\n\t\tstd::this_thread::sleep_for(std::chrono::milliseconds(60));\n\t}\n\treturn 0;\n}";
    for (char c : textA)
    {
        std::cout << c << std::flush;
        Beep(2500, 1);
        std::this_thread::sleep_for(std::chrono::milliseconds(60));
    }
    std::cout << "\n\n";
    system("pause");
    system("cls");
    for (char c : textB)
    {
        std::cout << c << std::flush;
        Beep(2500, 1);
        std::this_thread::sleep_for(std::chrono::milliseconds(60));
    }
    std::cout << "\n\n";
    system("pause");
    system("cls");
    for (char c : textC)
    {
        std::cout << c << std::flush;
        Beep(2500, 1);
        std::this_thread::sleep_for(std::chrono::milliseconds(60));
    }
    std::cout << "\n\n";
    system("pause");
    system("cls");
    return 0;
}
