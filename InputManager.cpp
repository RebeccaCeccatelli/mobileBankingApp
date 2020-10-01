//
// Created by Rebecca on 28/09/2020.
//

#include "InputManager.h"

#include <iostream>

using namespace std;

const unsigned int MAX_ATTEMPTS = 5;

void InputManager::manageInput(InputManager *specificClass) {
    if (!specificClass->isCorrectInput()) {
        if (attempts <= MAX_ATTEMPTS) {
            cout << "Your input is not correct (attempt nr = " << attempts << "). Try Again. " << endl;
            attempts++;
            specificClass->tryAgain();
        } else {
            cerr << "More than five uncorrect inputs." << endl;
            attempts = 1;
            specificClass->enableFailureRoutine();
        }
    }
    attempts = 1;
}
