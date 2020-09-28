//
// Created by Rebecca on 28/09/2020.
//

#ifndef MOBILE_BANKING_APP_ACCESSMANAGER_H
#define MOBILE_BANKING_APP_ACCESSMANAGER_H

#include <iostream>
#include <string>
#include <list>

using namespace std;

class AccessManager {
public:
    AccessManager();

    bool login();  // per adesso niente logout (callback?)
    const string &getName() const;

private:

    void askToRemember();

    bool checkCredentials();

    bool areCorrectCredentials();

    void setTitolarCode();

    void setRemembered(bool rem);

    void setClientName();

    void setPIN();

    void setFirstLogin(bool l);

    void resetInfo();

    unsigned int titolarCode;
    unsigned int PIN;
    string clientName{"client"};
    bool remembered{false};
    bool firstLogin{true};     //TODO rivedere nome

    list<pair<unsigned int, unsigned int>> acceptableCredentials;
};

#endif //MOBILE_BANKING_APP_ACCESSMANAGER_H
