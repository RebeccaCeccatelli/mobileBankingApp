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

    const string &getName() const;
    void login();

private:
    void checkCredentials();

    bool isCorrectInput() override;
    void tryAgain() override;
    void enableFailureRoutine() override;

    void setPIN();
    void resetPIN();

    void serialize() const;
    static bool deserialize();

    unsigned int PIN{0};
    bool firstLogin{true};

    AccountsManager accountsManager;
    SmartLock smartLock;

    list<Account> accounts;
};

#endif //MOBILE_BANKING_APP_ACCESSMANAGER_H
