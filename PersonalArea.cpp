//
// Created by Rebecca on 28/09/2020.
//

#include "PersonalArea.h"

#include <iostream>

#include "utilityFunctions.h"

using namespace std;
using namespace utilityFunctions;

void PersonalArea::setClientName(const string &cname) {
    clientName = cname;
}

void PersonalArea::display() {
    cout << endl << "*** Hi, " << clientName << "! This is your personal area. ***" << endl
        << "What would you like to do?" << endl;
    cout << "1) Banking accounts. " << endl << "2) My Profile. " << endl << "3) Bank services. " << endl
         << "4) Archive. " << endl << "5) Alerts. " << endl << "6) Reminders. " << endl << "0) logout. "
         << endl;

    cout << "Choose action (enter the corresponding number): " << endl;

    manageInput();
}


bool PersonalArea::isCorrectInput() {
    bool correct = true;
    string input = getStringInput();

    if (input == "1")
        cout << "To implement - banking accounts." << endl;
    else if (input == "2")
        cout << "To implement - my profile." << endl;
    else if (input == "3")
        cout << "To implement - bank services." << endl;
    else if (input == "4")
        cout << "To implement - archive." << endl;
    else if (input == "5"){
        alertsManager.setClientName(clientName);    //forse includere setName all'interno di altro. think
        alertsManager.displayUserInterface();
    }
    else if (input == "6") {
        remindersManager.setClientName(clientName);
        remindersManager.displayUserInterface();
    }
    else if (input == "0")
        setGoBack(true);

    else
        correct = false;

    return correct;
}

void PersonalArea::tryAgain() {
    display();
}

void PersonalArea::enableFailureRoutine() {
    cout << "There is no maximum limit, you can try again. " << endl;
    display();
}

