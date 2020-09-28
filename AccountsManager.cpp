//
// Created by Rebecca on 28/09/2020.
//

#include "AccountsManager.h"

#include <iostream>

#include "utilityFunctions.h"

using namespace std;
using namespace utilityFunctions;

bool AccountsManager::wantToSwitchAccount() {
    cout << "Do you want to switch account?" << endl;

    manageInput(this);

    return answer;
}

bool AccountsManager::isCorrectInput() {
    bool correct = false;

    string input = getStringInput();
    if (input == "yes") {
        cout << "Switch account" << endl;
        answer = true;

        correct = true;
    }
    else if (input == "no") {
        cout << "I'll stay" << endl;
        answer = false;

        correct = true;
    }
    return correct;
}

void AccountsManager::tryAgain() {
    wantToSwitchAccount();
}

void AccountsManager::enableFailureRoutine() {
    cout << "You're being redirected to our Welcome Page. " << endl;
}
