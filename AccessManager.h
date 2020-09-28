//
// Created by Rebecca on 28/09/2020.
//

#ifndef MOBILE_BANKING_APP_ACCESSMANAGER_H
#define MOBILE_BANKING_APP_ACCESSMANAGER_H
#include <iostream>
#include <string>

using namespace std;

class AccessManager {
public:
    void login();

    void logout();

    void returnToPreviousPage();

    const string &getName() const;

private:
    void askToRemember();

    void setRemembered(bool rem);

    bool isRemembered(string answer);

    void setTitolarCode(unsigned long int titCode);

    void setPIN(int pin);

    void setClientName(string cName);


    unsigned long int titolarCode;
    int PIN;
    string clientName = "client";
    bool remembered;

};

#endif //MOBILE_BANKING_APP_ACCESSMANAGER_H
