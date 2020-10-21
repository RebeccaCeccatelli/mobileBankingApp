//
// Created by rebecca on 10/15/20.
//

#ifndef MOBILE_BANKING_APP_SECURITYMANAGER_H
#define MOBILE_BANKING_APP_SECURITYMANAGER_H

#include <string>

#include "InputManager.h"

using namespace std;

class SecurityManager : public InputManager {
public:
    SecurityManager() = default;
    SecurityManager(string question, string answer, bool digKey);

    void serialize(const string& cname) const;
    static SecurityManager deserialize(const string& extractedPath);

private:
    void display() override;

    bool isCorrectInput(const string &input) override;

    bool askSecurityQuestion() const;
    void changeDigitalKeySetting();
    void changeSecurityQuestion();

    bool digitalKey{false};
    pair<string,string> securityQuestion{make_pair("none", "none")};
};


#endif //MOBILE_BANKING_APP_SECURITYMANAGER_H
