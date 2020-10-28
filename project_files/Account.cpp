//
// Created by rebecca on 10/27/20.
//

#include "Account.h"

bool Account::areCorrectCredentials(const string& titCode, const string& pin) const {
    bool correct = false;
    if (make_pair(titCode,pin) == acceptableCredentials)
        correct = true;
    return correct;
}

void Account::enter() {
    personalArea.setClientName(clientName);
    personalArea.displayUserInterface();
}
