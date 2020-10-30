//
// Created by rebecca on 10/27/20.
//

#include "AccessManager.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string AccessManager::NO = "no";

void AccessManager::setPIN(string pin) {
    PIN = move(pin);
}

void AccessManager::setTitolarCode(string titCode) {
    titolarCode = move(titCode);
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
    if (line == NO)
        firstLogin = false;

    iFile.close();

    return firstLogin;
}

bool AccessManager::isFirstLogin() const {
    return firstLogin;
}

void AccessManager::resetPIN() {
    PIN = "0";
}

void AccessManager::setFirstLogin(bool login) {
    firstLogin = login;
}

AccessManager::AccessManager() {
    accounts.emplace_back("1234567","12345","mario_rossi");
    accounts.emplace_back("1111111","11111","elisabetta_fellini");
    accounts.emplace_back("7654321","76543","lorenzo_cappelli");
    accounts.emplace_back("7777777","77777","eleonora_frangetti");
    accounts.emplace_back("1000000","10000","rebecca_ceccatelli");

    firstLogin = deserialize();

}

bool AccessManager::checkCredentials() {

    for (auto& account : accounts){
        if (account.areCorrectCredentials(titolarCode,PIN)) {
            currentAccount = &account;
            return true;
        }
    }
    return false;
}

void AccessManager::enter() {
    if (currentAccount)
        currentAccount->enter();
}

const string &AccessManager::getTitolarCode() const {
    return titolarCode;
}

void AccessManager::addAccount(const string& titCode, const string& pin, string clientName) {
    accounts.emplace_back(titCode, pin, move(clientName));
}


