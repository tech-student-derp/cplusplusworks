#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

int main() {
    char e = '*';

    for (int i = 0, j = 0; i <= j; i++) {
        cout << e << flush;
        this_thread::sleep_for(50ms);
        cout << e << j++;
    }
}
