#include <iostream>
#include <thread>   // for sleep_for
#include <chrono>   // for milliseconds

using namespace std;

void typewriter(const string& text, int delay_ms = 50) {
    for (char c : text) {
        cout << c << flush; // print immediately
        this_thread::sleep_for(chrono::milliseconds(delay_ms));
    }
    cout << endl; // move to next line after text finishes
}

int main() {
    typewriter("Hello, world! This is a typewriter effect.", 100);
    typewriter("You can control the speed by changing the delay.", 50);
}
