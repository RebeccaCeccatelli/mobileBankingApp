//
// Created by Rebecca on 28/09/2020.
//

#include "InputManager.h"

#include <iostream>

using namespace std;

const unsigned int MAX_ATTEMPTS = 5;

void InputManager::manageInput(string input) {
    if (!isCorrectInput(move(input))) {
        if (attempts <= MAX_ATTEMPTS) {
            cout << "Your input is not correct (attempt nr = " << attempts << "). Try Again. " << endl;
            attempts++;
            tryAgain();
        } else {
            cerr << "More than five uncorrect inputs." << endl;
            attempts = 1;
            enableFailureRoutine();
        }
    }
    attempts = 1;
}
