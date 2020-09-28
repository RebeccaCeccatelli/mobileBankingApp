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

void AccessManager::login() {
    cout << "*** Login page ***" << endl;
    if (!firstLogin) {
        if (remembered) {
            if (!wantToSwitchAccount())
                cout << clientName << ", your titolar code is already setted. " << endl;
            else {
                cout << "Removing previous info." << endl;
                setFirstLogin(true);
                askToRemember();
                cout << "Insert your titolar code: " << endl;
                setTitolarCode();
            }
        }
    }
    else if (firstLogin || !remembered) {
        askToRemember();
        cout << "Insert your titolar code: " << endl;
        setTitolarCode();
    }
    cout << "Insert your PIN: " << endl;
    setPIN();

    checkCredentials();
}

const string &AccessManager::getName() const {
    return clientName;
}

bool AccessManager::wantToSwitchAccount() {
    bool answer = false;
    cout << "Do you want to switch account?" << endl;
    if (getStringInput() == "yes"){
        resetInfo();
        setRemembered(false);
        setFirstLogin(true);
        answer = true;
    }
    return answer;
}

void AccessManager::askToRemember() {       //valutare se spostare in un'altra classe.
    cout << "Do you want your name and titolar code to be remembered by this App?" << endl;
    if (getStringInput() == "yes") {
        cout << "Then insert your name: " << endl;
        setClientName();
        setRemembered(true);
    }
    if (getStringInput() == "no") {
        cout << "Ok, then your titolar code will be removed. " << endl;
        resetInfo();
        setRemembered(false);
    }
}

void AccessManager::checkCredentials() {

    cout << "Checking Credentials..." << endl;

    static int attempts = 1;
    manageInput(this, attempts);
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

bool AccessManager::isCorrectInput() {

    for (auto account : accounts) {
        if (make_pair(titolarCode, PIN) == account.acceptableCredentials) {
            cout << "Credentials accepted. Logging in..." << endl;
            account.personalArea.displayScreen();
            return true;
        }
    }
    return false;
}

void AccessManager::tryAgain() {
    resetInfo();
    login();
}

void AccessManager::enableFailureRoutine() {
    resetInfo();
    cout << "You're being redirected to the Welcome Page. "
         << endl; //prima era metood exit(), provvisorio da sistemare TODO
    setRemembered(false);
    setFirstLogin(false);
    login();  //bug corretto ma scrittura non è chiara TODO
}
