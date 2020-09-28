//
// Created by Rebecca on 28/09/2020.
//

#include "AccountsManager.h"

#include <iostream>

#include "utilityFunctions.h"

using namespace std;
using namespace utilityFunctions;

bool AccountsManager::wantToSwitchAccount() {
    bool answer = false;
    cout << "Do you want to switch account?" << endl;

    static int attempts = 1;
    manageInput(this, attempts);

    return answer;
}

bool AccountsManager::isCorrectInput() {
    bool correct = true;
    string input = getStringInput();
    if (input == "yes") {
        cout << "Switch account" << endl; //TODO
    } else if (input == "no") {
        cout << "I'll stay" << endl; //TODO
    } else
        correct = false;
    return correct;
}

void AccountsManager::tryAgain() {
    wantToSwitchAccount();
}

void AccountsManager::enableFailureRoutine() {
    cout << "You're being redirected to our Welcome Page. " << endl;
}
