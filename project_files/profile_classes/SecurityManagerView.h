//
// Created by rebecca on 10/15/20.
//

#ifndef MOBILE_BANKING_APP_SECURITYMANAGERVIEW_H
#define MOBILE_BANKING_APP_SECURITYMANAGERVIEW_H

#include <string>

#include "../InputManager.h"
#include "SecurityManager.h"

using namespace std;

class SecurityManagerView : public InputManager {
public:
    virtual ~SecurityManagerView() = default;

    void serialize(const string& name) const;
    SecurityManagerView deserialize(const string& extractedPath);

private:
    void display() override;
    bool isCorrectInput(const string &input) override;

    bool askSecurityQuestion() const;
    void changeDigitalKeySetting();
    void changeSecurityQuestion();

    //attribute
    SecurityManager securityManager;
};


#endif //MOBILE_BANKING_APP_SECURITYMANAGERVIEW_H
