//
// Created by rebecca on 10/28/20.
//

#include "SecurityManager.h"

#include <fstream>

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
    return SecurityManager(question, answer, digKey);
}

const string &SecurityManager::getQuestion() const {
    return securityQuestion.first;
}

bool SecurityManager::checkAnswer(const string& answer) const {
    bool correct = false;
    if (securityQuestion.second == answer)
        correct = true;
    return correct;
}

void SecurityManager::changeDigitalKey() {
    digitalKey = !digitalKey;
}

bool SecurityManager::isDigitalKey() const {
    return digitalKey;
}

void SecurityManager::changeSecurityQuestion(string question, string answer) {
    securityQuestion.first = move(question);
    securityQuestion.second = move(answer);
}
