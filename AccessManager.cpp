//
// Created by Rebecca on 28/09/2020.
//

#include "AccessManager.h"

#include <iostream>
#include <string>

#include "utilityFunctions.h"

using namespace std;
using namespace utilityFunctions;

AccessManager::AccessManager() {
    accounts.emplace_back(1234567,12345,"Mario Rossi");
    accounts.emplace_back(1111111,11111,"Elisabetta Fellini");
    accounts.emplace_back(7654321,76543,"Lorenzo Cappelli");
    accounts.emplace_back(7777777,77777,"Eleonora Frangetti");
    accounts.emplace_back(1000000,10000,"Rebecca Ceccatelli");
}

void AccessManager::login(){
    cout << "*** Login page. *** " << endl;

    if (!firstLogin) {
        resetPIN();
        if (accountsManager.wantToSwitchAccount()) {
            smartLock.reset();
            firstLogin = true;
        }
    }

    smartLock.setTitolarCode();
    setPIN();

    checkCredentials();
}

const string &AccessManager::getName() const {
    return smartLock.getName();
}

bool AccessManager::isCorrectInput() {

    for (auto account : accounts) {
        if (make_pair(smartLock.getTitolarCode(), PIN) == account.acceptableCredentials) {
            cout << "Credentials accepted. Logging in..." << endl;
            if(firstLogin)
                firstLogin = smartLock.wantToRemember();
            account.personalArea.displayScreen();
            return true;
        }
    }
    return false;
}

void AccessManager::tryAgain() {
    login();
}

void AccessManager::enableFailureRoutine() {
    cout << "You're being redirected to the Welcome Page. " << endl;
    resetPIN();
    smartLock.reset();
    firstLogin = true;
}

void AccessManager::checkCredentials() {

    cout << "Checking Credentials..." << endl;

    manageInput(this);
}

void AccessManager::setPIN() {
    cout << "Insert PIN: " << endl;
    PIN = getNumInput();
}

void AccessManager::resetPIN() {
    PIN = 0;
}