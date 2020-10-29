//
// Created by rebecca on 10/15/20.
//

#include "ProfileView.h"

#include <iostream>
#include <fstream>

#include "../utilityFunctions.h"

using namespace utilityFunctions;
using namespace std;

const string NAME = "1";
const string ADDRESS = "2";
const string EMAIL = "3";
const string TEL_NUMBER = "4";
const string NEWSLETTER = "5";
const string BACK = "0";

void ProfileView::serialize(const string &name) const {
    profile.serialize(name);
}

ProfileView ProfileView::deserialize(const string &extractedPath) {
    profile = Profile::deserialize(extractedPath);
    return *this;
}

void ProfileView::display() {
    cout << endl << "*** Personal informations. ***" << endl;
    cout << "-Client name: " << profile.getName() << " (1)" << endl;
    cout << "-Residential address: " <<  profile.getResidentialAddress() << " (2)" << endl;
    cout << "-Email: " << profile.getEmail() << " (3)" << endl;
    cout << "-Telephone number: " << profile.getTelephoneNumber() << " (4)" << endl;
    cout << "-Inscribed to newsletter: ";
    if (profile.isNewsletter())
        cout << "yes" << " (5)" << endl;
    else
        cout << "no" << " (5)" << endl;
    cout << "Enter the corresponding number to modify the information, (0) to go back." << endl;

    manageInput(getStringInput());
}

bool ProfileView::isCorrectInput(const string &input) {
    bool correct = true;

    if (input == NAME || input == ADDRESS || input == EMAIL || input == TEL_NUMBER) {
        cout << "Insert new: ";
        string newSetting = getLineInput();

        if (input == NAME)
            profile.setClientName(newSetting);
        else if (input == ADDRESS)
            profile.setResidentialAddress(newSetting);
        else if (input == EMAIL)
            profile.setEmail(newSetting);
        else if (input == TEL_NUMBER)
            profile.setTelephoneNumber(newSetting);
    }
    else if (input == NEWSLETTER)
        profile.changeNewsletterSettings();
    else if (input == BACK)
        setGoBack(true);
    else
        correct = false;

    return correct;
}