//
// Created by Rebecca on 28/09/2020.
//

#ifndef MOBILE_BANKING_APP_ACCESSMANAGER_H
#define MOBILE_BANKING_APP_ACCESSMANAGER_H

#include <string>
#include <list>

#include "Account.h"
#include "AccountsManager.h"
#include "SmartLock.h"
#include "InputManager.h"

using namespace std;

class AccessManager : public InputManager {
public:
    AccessManager();

    void login();
    const string &getName() const;

private:
    bool isCorrectInput() override;
    void tryAgain() override;
    void enableFailureRoutine() override;

    void checkCredentials();

    void setPIN();
    void resetPIN();


    unsigned int PIN;
    bool firstLogin{true};

    AccountsManager accountsManager;
    SmartLock smartLock;

    list<Account> accounts;
};

#endif //MOBILE_BANKING_APP_ACCESSMANAGER_H
