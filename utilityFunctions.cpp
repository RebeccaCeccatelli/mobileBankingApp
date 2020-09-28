//
// Created by Rebecca on 28/09/2020.
//

#include "utilityFunctions.h"

#include <iostream>
#include <string>

const unsigned int MAX_ATTEMPTS = 5;

const string utilityFunctions::getStringInput() {
    string input;
    cin >> input;
    return input;
}

const unsigned int utilityFunctions::getNumInput() {
    unsigned int num;
    cin >> num;
    return num;
}

void utilityFunctions::manageInput(InputManager *specificClass, int &attempts) {
    //se è statica è condivisa sempre, cercare modo di convididerla solo per tipo di errore TODO

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
