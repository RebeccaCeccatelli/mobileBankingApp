//
// Created by Rebecca on 28/09/2020.
//

#include "WelcomePage.h"

#include <iostream>
#include <string>

#include "utilityFunctions.h"

using namespace std;
using namespace utilityFunctions;

const int MAX_ATTEMPTS = 5;

void WelcomePage::displayScreen() {
    cout << "*** Dear " << accessManager.getName() << ", Welcome! ***" << endl;
    cout << "Type 'login' to authenticate, 'exit' to close the application: " << endl;

    static int attempts = 1;
    manageInput(this, attempts);
}

bool WelcomePage::isCorrectInput() {
    bool correct = false;
    string input = getStringInput();

    if (input == "login") {
        correct = true;
        accessManager.login();
        /*if (!accessManager.login())
            displayScreen();*/
    } else if (input == "exit") {
        correct = true;
        exit();
    }
    return correct;
}


void WelcomePage::tryAgain() {
    displayScreen();
}

void WelcomePage::enableFailureRoutine() {
    cout << "You're being redirected to our Welcome Page." << endl;
}

void WelcomePage::exit() {
    cout << "Application closed. Goodbye. " << endl;
}

