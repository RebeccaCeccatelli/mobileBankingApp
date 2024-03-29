//
// Created by rebecca on 10/15/20.
//

#include "ProfileManagerView.h"

#include <iostream>
#include "../general_purpose_classes/utilityFunctions.h"

using namespace utilityFunctions;
using namespace std;

const string ProfileManagerView::PROFILE = "1";
const string ProfileManagerView::SECURITY_SETTINGS = "2";
const string ProfileManagerView::BANK_BRANCH = "3";

void ProfileManagerView::setClientName(const string &cname) {
    clientName = cname;
}

void ProfileManagerView::setAccountReference(Account *account) {
    securityManagerView.setAccountReference(account);
}

const SecurityManagerView* ProfileManagerView::getSMViewReference() const {
    return securityManagerView.getReference();
}

void ProfileManagerView::pullFromServer() {
    if (firstPull) {
        string directoryPath = "../server/" + clientName + "/profile/";

        profileView.deserialize(directoryPath + "personal_informations");
        securityManagerView.deserialize(directoryPath + "security_settings");
        bankBranch = BankBranchView::deserialize(directoryPath + "bank_branch");

        firstPull = false;
    }
}

void ProfileManagerView::updateServer(){
    cout << "Updating server..." << endl;
    profileView.serialize(clientName);
    securityManagerView.serialize(clientName);

    firstPull = true;
}

void ProfileManagerView::display() {
    pullFromServer();

    cout << endl << "*** Profile area. ***" << endl << "What would you like to do?" << endl;
    cout << "1) My profile." << endl << "2) My security settings."
        << endl << "3) My bank branch. " << endl << "0) Go back. " << endl;

    cout << "Choose action (enter the corresponding number): " << endl;

    manageInput(getStringInput());
}

bool ProfileManagerView::isCorrectInput(const string &input) {
    bool correct = true;

    if (input == PROFILE)
        profileView.displayUserInterface();
    else if (input == SECURITY_SETTINGS)
        securityManagerView.displayUserInterface();
    else if (input == BANK_BRANCH)
        bankBranch.display();
    else if (input == BACK) {
        updateServer();
        setGoBack(true);
    }
    else
        correct = false;

    return correct;
}

