//
// Created by Rebecca on 28/09/2020.
//

#include "PersonalArea.h"

#include <iostream>

#include "utilityFunctions.h"

using namespace std;
using namespace utilityFunctions;

void PersonalArea::displayScreen() {
    cout << "*** Hi, client! This is your personal area. ***" << endl << "What would you like to do?" << endl;
    cout << "1) Banking accounts. " << endl << "2) My Profile. " << endl << "3) Bank services. " << endl
         << "4) Archive. " << endl << "5) Alerts. " << endl << "6) Reminders. " << endl << "0) logout. "
         << endl;

    cout << "Choose action (enter the corrisponding number): " << endl;

    manageInput(this);
}


bool PersonalArea::isCorrectInput() {
    bool correct = true;
    string input = getStringInput();

    if (input == "1")
        cout << "To implement - banking accounts." << endl;
    else if (input == "2")
        cout << "To implement - my profile." << endl;
    else if (input == "3")
        cout << "To implement." << endl;
    else if (input == "4")
        cout << "To implement." << endl;
    else if (input == "5"){
        alertsManager.setClientName(clientName);
        alertsManager.displayScreen();
    }
    else if (input == "6") {
        remindersManager.setClientName(clientName);
        remindersManager.displayScreen();
    }
    else if (input == "0")
        cout << "To implement logout." << endl;
    else
        correct = false;

    return correct;
}

void PersonalArea::tryAgain() {
    displayScreen();
}

void PersonalArea::enableFailureRoutine() {
    cout << "More than five uncorrect inputs. There is no maximum limit, you can try again. " << endl;
    displayScreen();
}

void PersonalArea::setClientName(const string &cname) {
    clientName = cname;
}

