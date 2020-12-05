//
// Created by rebecca on 10/15/20.
//

#ifndef MOBILE_BANKING_APP_SECURITYMANAGERVIEW_H
#define MOBILE_BANKING_APP_SECURITYMANAGERVIEW_H

#include <string>

#include "../general_purpose_classes/InputManager.h"
#include "SecurityManager.h"

using namespace std;

class Account;

class SecurityManagerView : public InputManager {
public:
    SecurityManagerView() {}

    virtual ~SecurityManagerView() = default;

    void setAccountReference(Account* account);
    const SecurityManagerView* getReference() const;

    bool askPIN() const;

    void serialize(const string& name) const;
    SecurityManagerView deserialize(const string& extractedPath);

private:
    void display() override;
    bool isCorrectInput(const string &input) override;

    bool askSecurityQuestion() const;
    pair<bool,string> askNewPINTwice() const;

    void changeDigitalKeySetting();
    void changeSecurityQuestion();
    void changePIN();

    //attribute
    SecurityManager securityManager;

    //class constants
    static const string DIGITAL_KEY;
    static const string SECURITY_QUESTION;
    static const string PIN;
};


#endif //MOBILE_BANKING_APP_SECURITYMANAGERVIEW_H
