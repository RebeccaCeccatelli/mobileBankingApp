//
// Created by Rebecca on 28/09/2020.
//

#include "SmartLock.h"

#include <iostream>
#include <fstream>

#include "utilityFunctions.h"

using namespace std;
using namespace utilityFunctions;

bool SmartLock::wantToRemember() {
    cout << "Do you want your titolar code to be remembered by this App?" << endl;

    manageInput(this);

    return !remembered;
}

const unsigned int SmartLock::getTitolarCode() const {
    return titolarCode;
}

void SmartLock::setTitolarCode() {
    if (!remembered) {
        cout << "Insert titolar code: " << endl;
        titolarCode = getNumInput();
    }
}

const string &SmartLock::getNickname() const {
    return clientNickname;
}

void SmartLock::reset() {
    if (remembered) {
        clientNickname = "Client";
        setRemembered(false);
    }
    titolarCode = 0;
}

bool SmartLock::isCorrectInput() {
    bool correct = false;
    string input = getStringInput();

    if (input == "yes") {
        setRemembered(true);
        cout << "Ok! Insert a nickname: " << endl;
        setClientNickname();

        serialize();

        correct = true;
    }
    else if (input == "no") {
        cout << "Ok, your titolar code won't be remembered. You'll be asked again next time. " << endl;
        reset();
        correct = true;
    }

    return correct;
}

void SmartLock::tryAgain() {
    wantToRemember();
}

void SmartLock::enableFailureRoutine() {
    cout << "More than five uncorrect inputs. There is no maximum limit here, you can try again. " << endl;
    wantToRemember();
}

void SmartLock::setClientNickname() {
    clientNickname = getStringInput();
}

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

    string line, clientNickname;
    unsigned int titolarCode;
    bool remembered {false};

    int it = 0;
    while (getline(iFile,line,'-') && it<=3) {
        if (it == 1) {
            line.erase(0, 14);
            line.erase(line.end() - 2, line.end());
            titolarCode = stoi(line);
        }
        else if (it == 2) {
            line.erase(0, 17);
            line.erase(line.end() - 2, line.end());
            clientNickname = line;
        }
        else if (it == 3) {
            line.erase(0, 12);
            if (line == "yes")
                remembered = true;
        }
        it++;
    }
    iFile.close();

    return SmartLock(titolarCode,clientNickname,remembered);
}

