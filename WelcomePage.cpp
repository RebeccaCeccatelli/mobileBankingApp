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

void WelcomePage::display() {
    cout << endl << "*** Dear " << accessManager.getName() << ", Welcome! ***" << endl;
    cout << "Type 'login' to authenticate, 'exit' to close the application: " << endl;

    manageInput();
}

bool WelcomePage::isCorrectInput() {
    bool correct = false;
    string input = getStringInput();

    if (input == "login") {
        correct = true;
        accessManager.login();
    } else if (input == "exit") {
        correct = true;
        setGoBack(true);
        exit();
    }
    return correct;
}

void WelcomePage::tryAgain() {
    display();
}

void WelcomePage::enableFailureRoutine() {
    cout << "You're being redirected to our Welcome Page." << endl;
}

void WelcomePage::exit() {
    cout << "Application closed. Goodbye. " << endl;
}

