//
// Created by Rebecca on 28/09/2020.
//

#include "SmartLock.h"

#include <iostream>

#include "utilityFunctions.h"

using namespace std;
using namespace utilityFunctions;

void SmartLock::wantToRemember() {
    cout << "Do you want your name and titolar code to be remembered by this App?" << endl;

    static int attempts = 1;
    manageInput(this, attempts);
}

bool SmartLock::isCorrectInput() {
    bool correct = true;
    string input = getStringInput();
    if (input == "yes") {
        cout << "Then insert your name: " << endl;
        /*setClientName();
        setRemembered(true);*/
    } else if (input == "no") {
        cout << "Ok, then your titolar code will be removed. " << endl;
        /* resetInfo();
         setRemembered(false);*/
    } else
        correct = false;
    return correct;
}

void SmartLock::tryAgain() {
    wantToRemember();
}

void SmartLock::enableFailureRoutine() {
    cout << "You're being redirected to our WelcomePage. " << endl;
}
