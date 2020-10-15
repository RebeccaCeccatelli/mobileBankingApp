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
    cout << "1) Banking accounts. (not implemented yet) " << endl << "2) My Profile. (not implemented yet)"
         << endl << "3) Bank services. (not implemented yet)" << endl << "4) Archive. (not implemented yet)"
         << endl << "5) Alerts. " << endl << "6) Reminders. " << endl << "0) logout. " << endl;

    cout << "Choose action (enter the corresponding number): " << endl;

    manageInput(getStringInput());
}


bool PersonalArea::isCorrectInput(string input) {
    bool correct = true;

    if (input == "1")
        cout << "Not implemented yet - banking accounts." << endl;  //3
    else if (input == "2")
        cout << "Not implemented yet - my profile." << endl;       //1
    else if (input == "3")
        cout << "Not implemented yet - bank services." << endl;    //2
    else if (input == "4")
        cout << "Not implemented yet - archive." << endl;         //4
    else if (input == "5"){
        alertsManager.setClientName(clientName);
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

