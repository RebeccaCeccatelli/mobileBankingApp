//
// Created by rebecca on 10/27/20.
//

#include "SmartLock.h"

#include <iostream>
#include <fstream>

using namespace std;

const string YES = "yes";

void SmartLock::setRemembered(bool rem) {
    remembered = rem;
}

void SmartLock::serialize() const {
    string path = "../my_files/smart_lock";
    ofstream oFile (path);

    oFile << "-Titolar code: " << titolarCode;
    oFile << "\n\n-Client nickname: " << clientNickname;
    oFile << "\n\n-Remembered: ";
    if (remembered)
        oFile << "yes";
    else
        oFile << "no";

    oFile.close();
}

SmartLock SmartLock::deserialize() {
    ifstream iFile("../my_files/smart_lock");

    string line, clientNickname, titolarCode;
    bool remembered {false};

    int it = 0;
    while (getline(iFile,line,'-') && it<=3) {
        if (it == 1) {
            line.erase(0, 14);
            line.erase(line.end() - 2, line.end());
            titolarCode = line;
        }
        else if (it == 2) {
            line.erase(0, 17);
            line.erase(line.end() - 2, line.end());
            clientNickname = line;
        }
        else if (it == 3) {
            line.erase(0, 12);
            if (line == YES)
                remembered = true;
        }
        it++;
    }
    iFile.close();

    return SmartLock(titolarCode, clientNickname, remembered);
}

void SmartLock::setClientNickname(string cname) {
    clientNickname = move(cname);
}

void SmartLock::reset() {
    if (isRemembered()) {
        clientNickname = "client";
        setRemembered(false);
    }
    titolarCode = "0";

    ofstream oFile("../my_files/smart_lock", ofstream::trunc);
    oFile.close();
}

bool SmartLock::isRemembered() const{
    return remembered;
}

const string &SmartLock::getTitolarCode() {
    return titolarCode;
}

const string &SmartLock::getClientNickname() const {
    return clientNickname;
}

void SmartLock::setTitolarCode(const string& titCode) {
    titolarCode = titCode;
}
