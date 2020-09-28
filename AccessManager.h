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

    void login();    // per il momento no metodi di logout
    const string &getName() const;

protected:
    bool isCorrectInput() override;

    void tryAgain() override;

    void enableFailureRoutine() override;

private:

    void checkCredentials();

    void setTitolarCode();

    void setRemembered(bool rem);

    void setClientName();

    void setPIN();

    void setFirstLogin(bool l);

    void resetInfo();

private:
    unsigned int titolarCode;
    unsigned int PIN;
    string clientName{"client"};

    bool remembered{false};
    bool firstLogin{true};
    char purpose{1};
    AccountsManager accountsManager;
    SmartLock smartLock;

    list<Account> accounts;

};

#endif //MOBILE_BANKING_APP_ACCESSMANAGER_H
