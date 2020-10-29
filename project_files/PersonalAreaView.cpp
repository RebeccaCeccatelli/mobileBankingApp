//
// Created by Rebecca on 28/09/2020.
//

#include "PersonalAreaView.h"

#include <iostream>

#include "utilityFunctions.h"

using namespace std;
using namespace utilityFunctions;

const string BANKING_ACCOUNTS = "1";
const string PROFILE = "2";
const string ALERTS = "3";
const string REMINDERS = "4";
const string LOGOUT = "0";

void PersonalAreaView::setClientName(const string &cname) {
    clientName = cname;
}

void PersonalAreaView::display() {
    cout << endl << "*** Hi, " << clientName << "! This is your personal area. ***" << endl
        << "What would you like to do?" << endl;
    cout << "1) Banking accounts. (not implemented yet) " << endl << "2) My Profile."
         << endl << "3) Alerts. " << endl << "4) Reminders. " << endl << "0) logout. " << endl;

    cout << "Choose action (enter the corresponding number): " << endl;

    manageInput(getStringInput());
}


bool PersonalAreaView::isCorrectInput(const string &input) {
    bool correct = true;

    if (input == BANKING_ACCOUNTS)
        cout << "Not implemented yet - banking accounts." << endl;
    else if (input == PROFILE) {
        profileManagerView.setClientName(clientName);
        profileManagerView.displayUserInterface();
    }
    else if (input == ALERTS) {
        alertsManagerView.setClientName(clientName);
        alertsManagerView.displayUserInterface();
    }
    else if (input == REMINDERS) {
        remindersManager.setClientName(clientName);
        remindersManager.displayUserInterface();
    }
    else if (input == LOGOUT)
        setGoBack(true);

    else
        correct = false;

    return correct;
}

