//
// Created by Rebecca on 28/09/2020.
//

#include "SmartLockView.h"

#include <iostream>

#include "utilityFunctions.h"

using namespace std;
using namespace utilityFunctions;

bool SmartLockView::wantToRemember(const string& titolarCode) {
    cout << "Do you want your titolar code to be remembered by this App?" << endl;

    smartLock->setTitolarCode(titolarCode);
    manageInput(getStringInput());

    return !smartLock->isRemembered();
}

bool SmartLockView::isCorrectInput(const string &input) {
    bool correct = false;

    if (input == YES) {
        smartLock->setRemembered(true);
        cout << "Ok! Insert a nickname: " << endl;
        smartLock->setClientNickname(getStringInput());

        smartLock->serialize();

        correct = true;
    } else if (input == NO) {
        cout << "Ok, your titolar code won't be remembered. You'll be asked again next time. " << endl;
        smartLock->reset();

        correct = true;
    }

    return correct;
}

void SmartLockView::display() {
    wantToRemember(std::string()); //FIXME
}



