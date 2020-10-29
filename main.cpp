#include <iostream>

#include "project_files/login_classes/WelcomePage.h"

using namespace std;

int main() {
    cout << "Telephone screen. Press 1 to open your mobile banking app. " << endl;
    int input;
    cin >> input;

    WelcomePage welcomePage;

    while (input == 1) {

        welcomePage.displayUserInterface();
        cout << "Telephone screen. Press 1 to open your mobile banking app. " << endl;
        cin >> input;
    }

    return 0;
}