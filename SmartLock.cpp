//
// Created by Rebecca on 28/09/2020.
//

#include "SmartLock.h"

#include <iostream>

#include "utilityFunctions.h"

using namespace std;
using namespace utilityFunctions;

bool SmartLock::wantToRemember() {
    cout << "Do you want your titolar code to be remembered by this App?" << endl;

    manageInput(this);

    return !remembered;
}

const unsigned int SmartLock::getTitolarCode() const {
    return titolarCode;
}

void SmartLock::setTitolarCode() {
    if (!remembered) {
        cout << "Insert titolar code: " << endl;
        titolarCode = getNumInput();
    }
}

const string &SmartLock::getName() const {
    return clientNickname;
}

void SmartLock::reset() {
    if (remembered) {
        clientNickname = "Client";
        setRemembered(false);
    }
    titolarCode = 0;
}

bool SmartLock::isCorrectInput() {
    bool correct = false;
    string input = getStringInput();

    if (input == "yes") {
        setRemembered(true);
        cout << "Ok! Insert a nickname: " << endl;
        setClientNickname();

        correct = true;
    }
    else if (input == "no") {
        cout << "Ok, your titolar code won't be remembered. You'll be asked again next time. " << endl;
        reset();
        correct = true;
    }

    return correct;
}

void SmartLock::tryAgain() {
    wantToRemember();
}

void SmartLock::enableFailureRoutine() {
    cout << "More than five uncorrect inputs. There is no maximum limit here, you can try again. " << endl;
    wantToRemember();
}

void SmartLock::setClientNickname() {
    clientNickname = getStringInput();
}

void SmartLock::setRemembered(bool rem) {
    remembered = rem;
}
