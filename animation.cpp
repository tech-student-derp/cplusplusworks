#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

int main() {
    const char spinner[] = {'|', '/', '-', '\\'};

    for (int i = 0; i < 20; i++) {
        cout << "\r" << spinner[i % 4] << flush; // overwrite same spot
        this_thread::sleep_for(chrono::milliseconds(200));
    }
    cout << "\rDone!\n";
}
