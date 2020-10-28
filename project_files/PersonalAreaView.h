//
// Created by Rebecca on 28/09/2020.
//

#ifndef MOBILE_BANKING_APP_PERSONALAREAVIEW_H
#define MOBILE_BANKING_APP_PERSONALAREAVIEW_H

#include "InputManager.h"
#include "RemindersManager.h"
#include "AlertsManager.h"
#include "ProfileManagerView.h"

class PersonalAreaView : public InputManager {
public:
    virtual ~PersonalAreaView() = default;
    void setClientName(const string& cname);

private:
    void display() override;
    bool isCorrectInput(const string &input) override;

    //attributes
    RemindersManager remindersManager;
    AlertsManager alertsManager;
    ProfileManagerView profileManager;
    //BankingAccountsManager banking;

    string clientName{"client"};
};


#endif //MOBILE_BANKING_APP_PERSONALAREAVIEW_H
