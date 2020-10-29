//
// Created by Rebecca on 28/09/2020.
//

#include "AccountsManagerView.h"

#include <iostream>

#include "../general_purpose_classes/utilityFunctions.h"

using namespace std;
using namespace utilityFunctions;

const string YES = "yes";
const string NO = "no";

bool AccountsManagerView::wantToSwitchAccount() {
    cout << "Do you want to switch account?" << endl;

    manageInput(getStringInput());

    return answer;
}

bool AccountsManagerView::isCorrectInput(const string &input) {
    bool correct = false;

    if (input == YES) {
        cout << "Preparing to switch account..." << endl;
        answer = true;

        correct = true;
    }
    else if (input == NO) {
        cout << "Preparing your account access with smartlock facilities..." << endl;
        answer = false;

        correct = true;
    }
    return correct;
}

void AccountsManagerView::display() {
    wantToSwitchAccount();
}

void AccountsManagerView::enableFailureRoutine() {
    cout << "We assume you don't want to switch account." << endl;
}

