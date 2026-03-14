#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <cstdlib>
using namespace std;

void slowPrint(const string &text, int msDelay=50){
    for(char c : text){
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(msDelay));
    }
    cout << endl;
}

int main() {
    srand(time(0));
    cout << "Initializing hacker terminal...\n";
    this_thread::sleep_for(chrono::milliseconds(500));

    string commands[] = {
        "Scanning network ports...",
        "Bypassing firewall...",
        "Decrypting passwords...",
        "Fetching root access...",
        "Injecting malware...",
        "Dumping system info...",
        "Loading kernel modules...",
        "Extracting user data...",
        "Overclocking CPU...",
        "Accessing mainframe..."
    };

    string fakeFiles[] = {
        "/etc/passwd", "/home/user/.bashrc", "/var/log/syslog",
        "/usr/bin/python3", "/lib/modules/5.15/kernel.ko",
        "/tmp/tempfile1234", "/root/secret.txt"
    };

    // Simulate a “hacky” CLI session
    for(int i=0;i<10;i++){
        slowPrint(commands[i], 60);
        int fakeCount = rand()%50 + 10;
        for(int j=0;j<fakeCount;j++){
            string file = fakeFiles[rand()%8];
            slowPrint("Accessing: " + file, 20);
        }
        slowPrint("Operation complete: " + to_string(i+1) + "/10\n", 40);
    }

    slowPrint("Finalizing exploit...\n", 70);
    this_thread::sleep_for(chrono::milliseconds(500));

    // Fake hacker banner
    slowPrint("██████╗  █████╗  ██████╗██╗  ██╗", 10);
    slowPrint("██╔══██╗██╔══██╗██╔════╝██║  ██║", 10);
    slowPrint("██████╔╝███████║██║     ███████║", 10);
    slowPrint("██╔═══╝ ██╔══██║██║     ██╔══██║", 10);
    slowPrint("██║     ██║  ██║╚██████╗██║  ██║", 10);
    slowPrint("╚═╝     ╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝", 10);

    slowPrint("\nRoot access granted. Enjoy your totally legit hack.\n", 50);
}
