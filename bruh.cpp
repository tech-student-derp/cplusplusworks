#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <iomanip>
#include <cctype>

std::string f1() {
    std::array<int, 4> a1 = {98, 114, 117, 104};
    std::string s1;

    std::transform(a1.begin(), a1.end(), std::back_inserter(s1),
                   [](int x1) -> char { return static_cast<char>(x1); });

    s1.erase(std::remove_if(s1.begin(), s1.end(),
                [](char x2){ return !std::isprint(static_cast<unsigned char>(x2)); }),
             s1.end());

    std::stringstream ss1;
    for (char x3 : s1) {
        ss1 << std::setw(3) << x3;
    }

    return ss1.str();
}

int main() {
    std::string u1 = "Y";
    while (!u1.empty() && std::toupper(static_cast<unsigned char>(u1[0])) == 'Y') {
        std::string v1 = f1();

        if (!v1.empty()) {
            std::cout << "" << v1 << std::endl;
        }

        u1 = "n";
    }

    return 0;
}
