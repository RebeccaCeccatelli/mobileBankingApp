//
// Created by rebecca on 10/15/20.
//

#include "SecurityManagerView.h"

#include <iostream>
#include <fstream>

#include "../general_purpose_classes/utilityFunctions.h"

using namespace std;
using namespace utilityFunctions;

const string SecurityManagerView::DIGITAL_KEY = "1";
const string SecurityManagerView::SECURITY_QUESTION = "2";
const string SecurityManagerView::PIN = "3";

void SecurityManagerView::setAccountReference(Account *account) {
    securityManager.setAccountReference(account);
}

void SecurityManagerView::serialize(const string &name) const {
    securityManager.serialize(name);
}

SecurityManagerView SecurityManagerView::deserialize(const string &extractedPath) {
    securityManager = securityManager.deserialize(extractedPath);
    return *this;
}

void SecurityManagerView::display() {
    cout << endl << "*** Security settings. ***" << endl;
    cout << "-Digital Key: ";
    if (securityManager.isDigitalKey())
        cout << "enabled. (1)" << endl;
    else
        cout << "disabled. (1)" << endl;
    cout << "-Security question: setted. (2)" << endl;
    cout << "- Change PIN. (3)" << endl;
    cout << "Enter the corresponding number to modify the information, (0) to go back." << endl;

    manageInput(getStringInput());
}

bool SecurityManagerView::isCorrectInput(const string &input) {
    bool correct = true;

    if (input == DIGITAL_KEY)
        changeDigitalKeySetting();
    else if (input == SECURITY_QUESTION)
        changeSecurityQuestion();
    else if (input == PIN)
        changePIN();
    else if (input == BACK)
        setGoBack(true);
    else
        correct = false;

    return correct;
}

bool SecurityManagerView::askSecurityQuestion() const {
    bool correct = false;
    cout << "Before changing your settings, answer to this question (type '/' to confirm): "
        << endl << securityManager.getQuestion() << endl;
    if (securityManager.checkAnswer(getLineInput())) {
        cout << "Correct. " << endl;
        correct = true;
    }
    else
        cout << "Uncorrect answer. Error. " << endl;

    return correct;
}

void SecurityManagerView::changeDigitalKeySetting() {
    if (askSecurityQuestion()) {
        cout << "Changing digital key setting..." << endl;
        securityManager.changeDigitalKey();
    }
}

void SecurityManagerView::changeSecurityQuestion() {
    if (askSecurityQuestion()){
        string newQuestion, newAnswer;

        cout << "Insert your new question (type '/' to confirm): " << endl;
        newQuestion = getLineInput();
        cout << "Insert your new answer (type '/' to confirm): " << endl;
        newAnswer = getLineInput();

        securityManager.changeSecurityQuestion(newQuestion, newAnswer);
        cout << "Setted. " << endl;
    }
}

void SecurityManagerView::changePIN() {
    if (askPIN()){
        auto newPIN = askNewPINTwice();
        if(newPIN.first) {
            securityManager.setNewPin(newPIN.second);
            cout << "New pin setted. " << endl;
        }
    }
}

bool SecurityManagerView::askPIN() const {
    bool correct = false;

    if (securityManager.checkCurrentPIN(insertCurrentPIN())) {
        cout << "Correct. " << endl;
        correct = true;
    }
    else
        cout << "Uncorrect answer. Error. " << endl;

    return correct;
}

pair<bool, string> SecurityManagerView::askNewPINTwice() const {
    bool accepted = false;
    static int attempts{1};

    cout << "Insert your new PIN (first time): " << endl;
    string firstInput = getStringInput();
    cout << "Insert your new PIN (second time): " << endl;
    string secondInput = getStringInput();

    if (firstInput == secondInput){
        cout << "Accepted. " << endl;
        accepted = true, attempts = 1;
        return make_pair(accepted,firstInput);
    }
    else if (attempts <= 5){
        cout << "Inserted pins do not coincide (attempt nr = " << attempts << "). Try Again. " << endl;
        attempts++;
        return askNewPINTwice();
    }
    else{
        cout << "More than five uncorrect inputs. Negated. " << endl;
        return make_pair(accepted,"");
    }
}
