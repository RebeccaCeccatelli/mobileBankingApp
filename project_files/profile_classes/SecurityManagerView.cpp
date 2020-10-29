//
// Created by rebecca on 10/15/20.
//

#include "SecurityManagerView.h"

#include <iostream>
#include <fstream>

#include "../utilityFunctions.h"

using namespace std;
using namespace utilityFunctions;

const string DIGITAL_KEY = "1";
const string SECURITY_QUESTION = "2";
const string BACK = "0";

void SecurityManagerView::serialize(const string &name) const {
    securityManager.serialize(name);
}

SecurityManagerView SecurityManagerView::deserialize(const string &extractedPath) {
    securityManager = SecurityManager::deserialize(extractedPath);
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
    cout << "Enter the corresponding number to modify the information, (0) to go back." << endl;

    manageInput(getStringInput());
}

bool SecurityManagerView::isCorrectInput(const string &input) {
    bool correct = true;

    if (input == DIGITAL_KEY)
        changeDigitalKeySetting();
    else if (input == SECURITY_QUESTION)
        changeSecurityQuestion();
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
