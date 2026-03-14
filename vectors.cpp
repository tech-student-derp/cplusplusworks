#include <iostream>
#include <vector>

int main() {
    std::vector<double> gradesCont;
    double grades;

    std::cout << "Enter grades:\n";
    for (int i = 0; i < 5; ++i) {
        std::cout << ">> ";
        std::cin >> grades;
        gradesCont.push_back(grades);
    }

    for (double g : gradesCont) {
        std::cout << g << ", ";
    }

    double sum = 0;

    for (double g : gradesCont) sum += g;
    double avg = sum / gradesCont.size();
    std::cout << "\nAverage: " << avg;
}
