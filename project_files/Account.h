//
// Created by Rebecca on 28/09/2020.
//

#ifndef MOBILE_BANKING_APP_ACCOUNT_H
#define MOBILE_BANKING_APP_ACCOUNT_H

#include <list>
#include <string>

#include "PersonalAreaView.h"

using namespace std;

class Account {
public:
    Account(string titCode, string pin, string c) : acceptableCredentials{make_pair(move(titCode),move(pin))},
        clientName{move(c)} {}

    bool areCorrectCredentials(const string& titCode, const string& pin) const;
    void enter();

private:
    pair<string, string> acceptableCredentials;
    string clientName;
    PersonalAreaView personalAreaView;
};


#endif //MOBILE_BANKING_APP_ACCOUNT_H
