//
// Created by rebecca on 10/15/20.
//

#include "ProfileManager.h"

#include <iostream>
#include "utilityFunctions.h"

using namespace utilityFunctions;
using namespace std;

void ProfileManager::setClientName(const string &cname) {
    clientName = cname;
}
void ProfileManager::pullFromServer() {
    if (first) {
        string directoryPath = "../server/" + clientName + "/profile/";

        profile = Profile::deserialize(directoryPath + "personal_informations");
        securityManager = SecurityManager::deserialize(directoryPath + "security_settings");
        bankBranch = BankBranch::deserialize(directoryPath + "bank_branch");

        first = false;
    }
}

void ProfileManager::updateServer(){
    cout << "Updating server..." << endl;
    profile.serialize(clientName);
    securityManager.serialize(clientName);

    first = true;
}

void ProfileManager::display() {
    pullFromServer();

    cout << endl << "*** Profile area. ***" << endl << "What would you like to do?" << endl;
    cout << "1) My profile." << endl << "2) My products." << endl << "3) My security settings."
        << endl << "4) My bank branch. " << endl << "0) Go back. " << endl;

    cout << "Choose action (enter the corresponding number): " << endl;

    manageInput(getStringInput());
}

bool ProfileManager::isCorrectInput(const string &input) {
    bool correct = true;

    if (input == "1")
        profile.displayUserInterface();
    else if (input == "2")
        cout << "to implement - my products. "; //TODO
    else if (input == "3")
        securityManager.displayUserInterface();
    else if (input == "4")
        bankBranch.display();
    else if (input == "0") {
        updateServer();
        setGoBack(true);
    }
    else
        correct = false;

    return correct;
}

void ProfileManager::tryAgain() {
    display();
}

void ProfileManager::enableFailureRoutine() {
    cout << "There is no limit here, try again. " << endl;
    display();
}
