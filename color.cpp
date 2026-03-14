#include <iostream>
#include <string>
#include <chrono>
#include <thread>
using namespace std;

string name;
int score;

void wait(int s) {
    this_thread::sleep_for(chrono::seconds(s));
}

void fastw(int ms) {
    this_thread::sleep_for(chrono::milliseconds(ms));
}

void Rules() {
    cout << "Just answer the questions correctly. Or else you will lose some points.";
    wait(2);
}

void SpeechNo() {
    wait(3);
    cout << "I see your doubts on this game.\n";
    wait(1);
    cout << "I forgot to tell you the rules of this game. ";
    wait(1);
    cout << "The rules are simple.\n";
    wait(1);
    cout << "Simple as potatoes-";
    fastw(30);
    cout << "Oh wait yea... ";
    fastw(20);
    cout << "Is that what can I say?\n";
    wait(1);
    cout << "Huh who knows, you know what I mean.\n";
    wait(1);
    Rules();
    cout << "\nDo you understand? Don't tell me you don't, you can just read the top of it.\n";
    cout << "(I understand / I don't understand.)\n";
    wait(1);
}

void Intro() {
    const string DEV = "DEV"; // define your dev name
    string answer, realans;

    cout << "Hello user, may I know your name?\nYour name: ";
    wait(1);
    getline(cin, name);

    if (name == DEV) {
        wait(2);
        cout << "Hello master, welcome to debug mode.";
        cout << " (LETS PRETEND WE'RE HACKING)\n";
    }

    wait(1);
    cout << "Hello...";
    wait(1);
    cout << name;
    wait(1);
    cout << ". That is an interesting name there...";
    wait(1);
    cout << "Shall we start the game?\nYes or No? ";
    cin >> answer;

    // convert answer to lowercase for simple comparison
    for (char &c : answer) c = tolower(c);

    if (answer == "yes") {
        wait(1);
        cout << "Alright. ";
        wait(2);
        cout << "Let's begin...\n";
    }
    else if (answer == "no" || answer == "nope") {

        SpeechNo();
        cin.ignore(); // flush newline
        getline(cin, realans);

        // convert to lowercase for simple detection
        for (char &c : realans) c = tolower(c);

        if (realans.find("yea") != string::npos) {
            wait(1);
            cout << "Now we're talking...\n";
            fastw(30);
            cout << "Let's start.\n";
        } else {
            wait(2);
            for (int i = 1; i <= 3; i++) {
                wait(2);
                cout << ".";
            }
            wait(1);
            cout << "\nBruh.";
            fastw(30);
            cout << " You're trolling, aren't you?\n";
            wait(1);
            cout << "Guess you gotta read it again.\n";
            SpeechNo();
        }
    }
    else {
        wait(1);
        cout << "\nGod forbid you.\n";
        return; // can't return 0 in void
    }
}

void Questions() {
    cout << "\nQuestion number 1\n";
}

int main() {
    Intro();
    wait(2);
    Questions();
    return 0;
}
