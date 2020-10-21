//
// Created by Rebecca on 28/09/2020.
//

#ifndef MOBILE_BANKING_APP_PERSONALAREA_H
#define MOBILE_BANKING_APP_PERSONALAREA_H

#include "InputManager.h"
#include "RemindersManager.h"
#include "AlertsManager.h"
#include "ProfileManager.h"

class PersonalArea : public InputManager {
public:
    void setClientName(const string& cname);

private:
    void display() override;

    bool isCorrectInput(const string &input) override;

    string clientName{"client"};
    RemindersManager remindersManager;
    AlertsManager alertsManager;
    ProfileManager profileManager;
    //BankingAccountsManager banking;
};


#endif //MOBILE_BANKING_APP_PERSONALAREA_H
