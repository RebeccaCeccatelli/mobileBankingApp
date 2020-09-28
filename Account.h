//
// Created by Rebecca on 28/09/2020.
//

#ifndef MOBILE_BANKING_APP_ACCOUNT_H
#define MOBILE_BANKING_APP_ACCOUNT_H

#include <list>
#include <string>

#include "PersonalArea.h"

using namespace std;

struct Account {
    Account(unsigned int titCode, unsigned int pin, string c) : acceptableCredentials{make_pair(titCode,pin)}, client{move(c)} {}

    pair<unsigned int, unsigned int> acceptableCredentials;
    string client;
    PersonalArea personalArea;
};

#endif //MOBILE_BANKING_APP_ACCOUNT_H
