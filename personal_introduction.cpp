// Joshua P. Flores ACT AD 1B
#include <iostream>
#include <string>
using namespace std;
int main() {
    string name, proglang;
    int age;
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter your age: ";
    cin >> age;
    cout << "Enter your favorite programming language: ";
    cin >> proglang;
    cout << "Hi, my name is " << name << ". I am " << age << " and I love programming in " << proglang << "!";
    return 0;
}
