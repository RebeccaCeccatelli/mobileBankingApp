//
// Created by rebecca on 10/15/20.
//

#include "SecurityManager.h"

#include <iostream>
#include <fstream>

#include "utilityFunctions.h"

using namespace std;
using namespace utilityFunctions;

SecurityManager::SecurityManager(string question, string answer, bool digKey) : digitalKey{digKey} {
    securityQuestion = make_pair(move(question),move(answer));
}

void SecurityManager::serialize(const string &cname) const {
    string path = "../server/" + cname + "/profile/security_settings";
    ofstream oFile(path);

    oFile << "-Security question: " << securityQuestion.first;
    oFile << "\n\n-Relative answer: " << securityQuestion.second;
    oFile << "\n\n-Digital key: ";
    if (digitalKey)
        oFile << "yes";
    else
        oFile << "no";

    oFile.close();
}

SecurityManager SecurityManager::deserialize(const string &extractedPath) {
    ifstream iFile(extractedPath);

    string line, question, answer;
    bool digKey{false};

    int it = 0;
    while (getline(iFile,line,'-') && it<=3){
        if (it == 1){
            line.erase(0,19);
            line.erase(line.end()-2,line.end());
            question = line;
        }
        if (it == 2) {
            line.erase(0, 17);
            line.erase(line.end() - 2, line.end());
            answer = line;
        }
        if (it == 3) {
            line.erase(0, 23);
            if (line == "yes")
                digKey = true;
        }
        it++;
    }
    return SecurityManager(question,answer,digKey);
}

void SecurityManager::display() {
    cout << endl << "*** Security settings. ***" << endl;
    cout << "-Digital Key: ";
    if (digitalKey)
        cout << "enabled. (1)" << endl;
    else
        cout << "disabled. (1)" << endl;
    cout << "-Security question: setted. (2)" << endl;
    cout << "Enter the corresponding number to modify the information, (0) to go back." << endl;

    manageInput(getStringInput());
}

bool SecurityManager::isCorrectInput(const string &input) {
    bool correct = true;

    if (input == "1")
        changeDigitalKeySetting();
    else if (input == "2")
        changeSecurityQuestion();
    else if (input == "0")
        setGoBack(true);
    else
        correct = false;

    return correct;
}

bool SecurityManager::askSecurityQuestion() const {
    bool correct = false;
    cout << "Before changing your settings, answer to this question (type '/' to confirm): "
        << endl << securityQuestion.first << endl;
    if (securityQuestion.second == getLineInput()) {
        cout << "Correct. " << endl;
        correct = true;
    }
    else
        cout << "Uncorrect answer. Error. " << endl;

    return correct;
}

void SecurityManager::changeDigitalKeySetting() {
    if (askSecurityQuestion()) {
        cout << "Changing digital key setting..." << endl;
        digitalKey = !digitalKey;
    }
}

void SecurityManager::changeSecurityQuestion() {
    if (askSecurityQuestion()){
        cout << "Insert your new question (type '/' to confirm): " << endl;
        securityQuestion.first = getLineInput();
        cout << "Insert your new answer (type '/' to confirm): " << endl;
        securityQuestion.second = getLineInput();
        cout << "Setted. " << endl;
    }
}
