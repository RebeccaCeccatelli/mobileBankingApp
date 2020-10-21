//
// Created by rebecca on 10/15/20.
//

#ifndef MOBILE_BANKING_APP_PROFILEMANAGER_H
#define MOBILE_BANKING_APP_PROFILEMANAGER_H

#include <string>

#include "InputManager.h"
#include "Interface.h"
#include "Profile.h"
#include "SecurityManager.h"
#include "BankBranch.h"

using namespace std;

class ProfileManager : public InputManager, public Interface {
public:
    void setClientName(const string& cname);

private:
    void pullFromServer();
    void updateServer();

    void display() override;

    bool isCorrectInput(const string &input) override;
    void tryAgain() override;
    void enableFailureRoutine() override;

    string clientName;
    Profile profile;
    BankBranch bankBranch;
    SecurityManager securityManager;

    bool first{true};    //rendere più chiaro l'uso di questo booleano FIXME
};


#endif //MOBILE_BANKING_APP_PROFILEMANAGER_H
