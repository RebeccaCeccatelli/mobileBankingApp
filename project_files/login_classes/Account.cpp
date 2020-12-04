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
    personalAreaView.setClientName(clientName);
    personalAreaView.setAccountReference(this);
    personalAreaView.displayUserInterface();
}

void Account::setPIN(string pin) {
    acceptableCredentials.second = move(pin);
}

const string &Account::getPIN() const {
    return acceptableCredentials.second;
}
