//
// Created by Rebecca on 28/09/2020.
//

#include "AccessManager.h"

#include <iostream>
#include <fstream>
#include <string>

#include "utilityFunctions.h"

using namespace std;
using namespace utilityFunctions;

AccessManager::AccessManager() {
    accounts.emplace_back(1234567,12345,"mario_rossi");
    accounts.emplace_back(1111111,11111,"elisabetta_fellini");
    accounts.emplace_back(7654321,76543,"lorenzo_cappelli");
    accounts.emplace_back(7777777,77777,"eleonora_frangetti");
    accounts.emplace_back(1000000,10000,"rebecca_ceccatelli");

    firstLogin = deserialize();
    if (!firstLogin)
        smartLock = SmartLock::deserialize();
}

const string &AccessManager::getName() const {
    return smartLock.getNickname();
}

void AccessManager::login(){
    cout << endl << "*** Login page. *** " << endl;

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

void AccessManager::checkCredentials() {

    cout << "Checking Credentials..." << endl;

    manageInput();
}

bool AccessManager::isCorrectInput(const string &input) {

    for (auto& account : accounts) {
        if (make_pair(smartLock.getTitolarCode(), PIN) == account.acceptableCredentials) {
            cout << "Credentials accepted. Logging in..." << endl;
            if(firstLogin) {
                firstLogin = smartLock.wantToRemember();
                serialize();
            }
            account.personalArea.setClientName(account.clientName);

            account.personalArea.displayUserInterface();

            return true;
        }
    }
    return false;
}

void AccessManager::display() {
    login();
}

void AccessManager::enableFailureRoutine() {
    cout << "You're being redirected to the Welcome Page. " << endl;
    resetPIN();
    smartLock.reset();
    firstLogin = true;
}

void AccessManager::setPIN() {
    cout << "Insert PIN: " << endl;
    PIN = getNumInput();
}

void AccessManager::resetPIN() {
    PIN = 0;
}

void AccessManager::serialize() const {
    ofstream oFile("../my_files/first_login");

    oFile << "First login: ";
    if (firstLogin)
        oFile << "yes";
    else
        oFile << "no";
}

bool AccessManager::deserialize() {
    bool firstLogin = true;
    ifstream iFile("../my_files/first_login");

    string line;
    getline(iFile,line);
    line.erase(0,13);
    if (line == "no")
        firstLogin = false;

    iFile.close();

    return firstLogin;
}

