//
// Created by rebecca on 10/27/20.
//

#ifndef MOBILE_BANKING_APP_ACCESSMANAGER_H
#define MOBILE_BANKING_APP_ACCESSMANAGER_H

#include <string>
#include <list>

#include "Account.h"

using namespace std;

class AccessManager {
public:
    AccessManager();

    bool checkCredentials();
    void enter();

    const string& getTitolarCode() const;
    void setTitolarCode(string titCode);
    void setPIN(string pin);
    void resetPIN();
    void setFirstLogin(bool login);
    bool isFirstLogin() const;

    void serialize() const;

    //method added to facilitate unit-testing
    void addAccount(const string& titCode, const string& pin, string clientName);

private:
    static bool deserialize();

//attributes
    list<Account> accounts;

    string PIN;
    string titolarCode;

    bool firstLogin;
    Account* currentAccount{nullptr};
};


#endif //MOBILE_BANKING_APP_ACCESSMANAGER_H
