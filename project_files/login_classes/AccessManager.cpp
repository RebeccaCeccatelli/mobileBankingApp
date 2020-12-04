//
// Created by rebecca on 10/27/20.
//

#include "AccessManager.h"

#include <iostream>
#include <fstream>
#include <string>
#include <boost/archive/text_iarchive.hpp>

using namespace std;

const string AccessManager::NO = "no";

AccessManager::AccessManager() {
    ifstream iFile("/home/rebecca/CLionProjects/Laboratorio_di_programmazione/mobile_banking_app/server/existing_accounts");
    text_iarchive ia(iFile);
    ia >> *this;
    iFile.close();

    firstLogin = deserializeFirstLogin();
}

void AccessManager::setPIN(string pin) {
    PIN = move(pin);
}

void AccessManager::setTitolarCode(string titCode) {
    titolarCode = move(titCode);
}

void AccessManager::serializeFirstLogin() const {
    ofstream oFile("../saved_files/first_login");

    oFile << "First login: ";
    if (firstLogin)
        oFile << "yes";
    else
        oFile << "no";
}

bool AccessManager::deserializeFirstLogin() {
    bool firstLogin = true;
    ifstream iFile("../saved_files/first_login");

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


