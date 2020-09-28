//
// Created by Rebecca on 28/09/2020.
//

#include "AccessManager.h"

#include <iostream>
#include <string>

#include "utilityFunctions.h"

using namespace std;
using namespace utilityFunctions;

bool AccessManager::login() {
    cout << "*** Login page ***" << endl;
    if (!firstLogin && remembered)
        cout << clientName << ", your titolar code is already setted. " << endl;
    else {      //TODO possibilità di cambiare account (altro titolare)
        askToRemember();       //TODO chiede ogni volta solo se si è detto no
        cout << "Insert your titolar code: " << endl;
        setTitolarCode();

    }
    cout << "Insert your PIN: " << endl;
    setPIN();

    bool successful = checkCredentials();
    resetInfo();
    return successful;
}

const string &AccessManager::getName() const {
    return clientName;
}

void AccessManager::askToRemember() {
    cout << "Do you want your name and titolar code to be remembered by this App?" << endl;
    if (getStringInput() == "yes") {
        cout << "Then insert your name: " << endl;
        setClientName();

        setRemembered(true);
    } else {
        cout << "Ok, then your titolar code will be removed. " << endl;
        resetInfo();
    }
}

bool AccessManager::checkCredentials() {
    static int attempts = 1;
    bool correct = true;

    cout << "Checking Credentials..." << endl;

    if (!areCorrectCredentials()) {
        if (attempts <= 5) {
            cout << "Your input is not correct (attempt nr = " << attempts << "). Try Again. " << endl;
            attempts++, correct = false;
            resetInfo();
            login();
        } else if (attempts > 5) {
            cerr << "More than five uncorrect inputs." << endl;
            attempts = 1, correct = false;
            resetInfo();
            exit();   //FIXME errore qui: si ricorda il nome dopo avermi riportato alla welcome page e dice titCode setted.
        }
    }
    attempts = 1;
    setFirstLogin(false);
    return correct;
}

bool AccessManager::areCorrectCredentials() {

    for (auto cred : acceptableCredentials) {
        if (make_pair(titolarCode, PIN) == cred) {
            cout << "Logging in..." << endl;
            return true;
        }
    }
    return false;
}

void AccessManager::setClientName() {
    clientName = getStringInput();
}

void AccessManager::setTitolarCode() {
    titolarCode = getNumInput();
}

void AccessManager::setRemembered(bool rem) {
    remembered = rem;
}

void AccessManager::setPIN() {
    PIN = getNumInput();
}

void AccessManager::setFirstLogin(bool l) {
    firstLogin = l;
}

void AccessManager::resetInfo() {
    if (!remembered) {
        clientName = "client";
        titolarCode = 0;
    }
    PIN = 0;  //ok ma ricontrollare logica
}

AccessManager::AccessManager() {
    acceptableCredentials.emplace_back(1234567, 12345);
    acceptableCredentials.emplace_back(1111111, 11111);
    acceptableCredentials.emplace_back(7654321, 76543);
    acceptableCredentials.emplace_back(7777777, 77777);
    acceptableCredentials.emplace_back(00000000, 00000);
}
