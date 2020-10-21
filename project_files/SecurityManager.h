//
// Created by rebecca on 10/15/20.
//

#ifndef MOBILE_BANKING_APP_SECURITYMANAGER_H
#define MOBILE_BANKING_APP_SECURITYMANAGER_H

#include <string>

#include "InputManager.h"
#include "Interface.h"

using namespace std;

class SecurityManager : public InputManager, public Interface {
public:
    SecurityManager() = default;
    SecurityManager(string question, string answer, bool digKey);
    void display() override;

    void serialize(const string& cname) const;
    static SecurityManager deserialize(const string& extractedPath);
private:
    void changeDigitalKeySetting();
    void changeSecurityQuestion();
    bool askSecurityQuestion() const;

    bool isCorrectInput(const string &input) override;
    void tryAgain() override;
    void enableFailureRoutine() override;

    bool digitalKey{false};
    pair<string,string> securityQuestion{make_pair("empty", "empty")};
};


#endif //MOBILE_BANKING_APP_SECURITYMANAGER_H
