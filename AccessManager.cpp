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

bool AccessManager::login() {
    cout << "*** Login page ***" << endl;
    if (!firstLogin) {
        if (remembered){
            if (!wantToSwitchAccount())
                cout << clientName << ", your titolar code is already setted. " << endl;
            else{
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

    return checkCredentials();
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

void AccessManager::askToRemember() {
    cout << "Do you want your name and titolar code to be remembered by this App?" << endl;
    if (getStringInput() == "yes") {
        cout << "Then insert your name: " << endl;
        setClientName();

        setRemembered(true);
    } else {
        cout << "Ok, then your titolar code will be removed. " << endl;
        resetInfo();
        setRemembered(false);
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
            cout << "More than five uncorrect inputs." << endl;
            attempts = 1, correct = false;
            resetInfo();
            exit();
            setRemembered(false);
            login();  //bug corretto ma scrittura non è chiara TODO
        }
    }
    attempts = 1;
    setFirstLogin(false);
    resetInfo();
    return correct;
}

bool AccessManager::areCorrectCredentials() {

    for (auto account : accounts) {
        if (make_pair(titolarCode, PIN) == account.acceptableCredentials) {
            cout << "Logging in..." << endl;
            account.personalArea.displayScreen();
            return true; //qui si entra nell'area personale
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