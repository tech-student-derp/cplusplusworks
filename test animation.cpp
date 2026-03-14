#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

int main() {
    int pos = 0;

    while (pos < 20) {
        // clear screen (not portable, just for demo)
        system("cls"); // use "clear" on Linux/Mac

        // draw animation frame
        for (int i = 0; i < pos; i++) cout << " ";
        cout << "O" << endl;

        // move "O" to the right
        pos++;

        // control speed (60ms per frame ~ 16 FPS)
        this_thread::sleep_for(chrono::milliseconds(60));
    }
}
