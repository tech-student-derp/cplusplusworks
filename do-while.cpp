#include <iostream>

void funct() {
    bool p, q, r, x;

    std::cout << "(p -> q) V (r V p)";

    std::cout << "\n\nIf p = true, q = true, r = true: \n";
    std::cout << "(p -> q) V (r V p): ";

    x = (!p || q) && (r && p);

    if (x == true) std::cout << "True";
    else std::cout << "False";

    std::cout << "\n\nNow let's say: p = false, q = true, r = false:\n";
    std::cout << "(~p -> q) V (~r V ~p): ";

    x = (p || !q) && (!r && !p);

    if (x == true) std::cout << "True";
    else std::cout << "False";

    std::cout << "\n\nNow again, let's set the r = true:\n";
    std::cout << "(~p -> q) V (r V ~p): ";

    x = (p || !q) && (!r && p);

    if (x == true) std::cout << "True";
    else std::cout << "False";

    std::cout << "\n\nNow again, let's set all variables to false :\n";
    std::cout << "(~p -> ~q) V (~r V ~p): ";

    x = (!p || !q) && (!r && !p);

    if (x == true) std::cout << "True";
    else std::cout << "False";

    std::cout << "\n\nLet's say p = true, q = true:\n";
    std::cout << "(p -> q) V (~r V p): ";

    x = (p || q) && (!r && p);

    if (x == true) std::cout << "True";
    else std::cout << "False";

    std::cout << "\n\nOk, now how about p = true, q = true, r = false\n";
    std::cout << "q ^ (~r V p): ";

    x = q || (!r && p);

    if (x == true) std::cout << "True";
    else std::cout << "False";
}

int main() {
    funct();
    return 0;
}
