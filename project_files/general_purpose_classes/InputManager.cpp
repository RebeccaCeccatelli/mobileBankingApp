//
// Created by Rebecca on 28/09/2020.
//

#include "InputManager.h"

#include <iostream>

using namespace std;

const unsigned int InputManager::MAX_ATTEMPTS = 5;

void InputManager::manageInput(const string &input) {
    if (!isCorrectInput(input)) {
        if (attempts <= MAX_ATTEMPTS) {
            cout << "Your input is not correct (attempt nr = " << attempts << "). Try Again. " << endl;
            attempts++;
            tryAgain();
        } else {
            cout << "More than five uncorrect inputs." << endl;
            attempts = 1;
            enableFailureRoutine();
        }
    }
    attempts = 1;
}

void InputManager::tryAgain() {
    display();
}

void InputManager::enableFailureRoutine() {
    cout << "There is no maximum limit here, you can try again. " << endl;
    display();
}
