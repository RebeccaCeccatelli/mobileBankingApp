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
    cout << "Dear " << accessManager.getName() << ", Welcome!" << endl;
    cout << "Type 'login' to authenticate, 'exit' to close the application: " << endl;
    manageInput();
}

void WelcomePage::manageInput() {
    static int attempts = 1;

    if (!isCorrectInput()) {
        if (attempts <= MAX_ATTEMPTS) {
            cout << "Your input is not correct (attempt nr = " << attempts << "). Try Again. ";
            attempts++;
            displayScreen();
        } else {
            cerr << "More than five uncorrect inputs." << endl;
            attempts = 1;
            exit();
        }
    }
    attempts = 1;
}

bool WelcomePage::isCorrectInput() {
    bool correct = false;
    string input = getInput();

    if (input == "login") {
        correct = true;
        accessManager.login();
    } else if (input == "exit") {
        correct = true;
        exit();
    }
    return correct;
}

void WelcomePage::exit() {
    cout << "Application closed. Goodbye." << endl;
}