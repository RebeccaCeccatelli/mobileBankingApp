//
// Created by rebecca on 10/27/20.
//

#ifndef MOBILE_BANKING_APP_ACCESSMANAGER_H
#define MOBILE_BANKING_APP_ACCESSMANAGER_H

#include <string>
#include <list>
#include <boost/serialization/list.hpp>

#include "Account.h"

using namespace std;
using namespace boost::archive;

class AccessManager {
public:
    explicit AccessManager(const string& testing = "no");

    bool checkCredentials();
    void enter();

    const string& getTitolarCode() const;
    void setTitolarCode(string titCode);
    void setPIN(string pin);
    void resetPIN();
    void setFirstLogin(bool login);
    bool isFirstLogin() const;

    void serializeFirstLogin() const;

    //method added to facilitate unit-testing
    void addAccount(const string& titCode, const string& pin, string clientName);

private:
    friend class boost::serialization::access;

    template<typename Archive>
    void serialize(Archive &ar, const unsigned int version){
        ar & accounts;
    }

    static bool deserializeFirstLogin();

    //attributes
    list<Account> accounts;

    string PIN;
    string titolarCode;

    bool firstLogin;
    Account* currentAccount{nullptr};
};


#endif //MOBILE_BANKING_APP_ACCESSMANAGER_H
