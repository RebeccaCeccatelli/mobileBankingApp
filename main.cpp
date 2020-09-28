#include <iostream>

#include "WelcomePage.h"

using namespace std;

int main() {
    int it = 1;
    WelcomePage welcomePage;
    while (it == 1) {
        welcomePage.displayScreen();
        cout << "press 1 to stay, 2 to quit" << endl;
        cin >> it;
    }
    return 0;
}