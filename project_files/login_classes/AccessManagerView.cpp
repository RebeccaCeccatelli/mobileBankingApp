//
// Created by Rebecca on 28/09/2020.
//

#include "AccessManagerView.h"

#include <iostream>
#include <string>

#include "../utilityFunctions.h"
#include "SmartLockView.h"
#include "AccountsManagerView.h"

using namespace std;
using namespace utilityFunctions;

AccessManagerView::AccessManagerView() {

    if (!accessManager.isFirstLogin())
        smartLock = SmartLock::deserialize();
}

const string &AccessManagerView::getName() const {
    return smartLock.getClientNickname();
}

void AccessManagerView::login(){
    AccountsManagerView accountsManagerView;

    cout << endl << "*** Login page. *** " << endl;

    if (!accessManager.isFirstLogin()) {
        accessManager.resetPIN();

        if (accountsManagerView.wantToSwitchAccount()) {
            smartLock.reset();
            accessManager.setFirstLogin(true);
        }
    }

    accessManager.setTitolarCode(obtainTitolarCode());

    cout << "Insert PIN: " << endl;
    accessManager.setPIN(getStringInput());

    manageInput();
}


bool AccessManagerView::isCorrectInput(const string &input) {
    bool correct = false;

    cout << "Checking Credentials..." << endl;
    if (accessManager.checkCredentials()){
        cout << "Credentials accepted. Logging in..." << endl;

        if (accessManager.isFirstLogin()) {
            SmartLockView smartLockView(&smartLock);
            accessManager.setFirstLogin(smartLockView.wantToRemember(accessManager.getTitolarCode()));

            accessManager.serialize();
        }
        accessManager.enter();

        correct = true;
    }

    return correct;
}

void AccessManagerView::display() {
    login();
}

void AccessManagerView::enableFailureRoutine() {
    cout << "You're being redirected to the Welcome Page. " << endl;
    accessManager.resetPIN();
    smartLock.reset();
    accessManager.setFirstLogin(true);
}

string AccessManagerView::obtainTitolarCode() {
    string titCode;

    if (smartLock.isRemembered())
        titCode = smartLock.getTitolarCode();
    else {
        cout << "Insert your titolar code: " << endl;
        titCode = getStringInput();
    }

    return titCode;
}

