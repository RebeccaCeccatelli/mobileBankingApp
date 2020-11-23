//
// Created by Rebecca on 28/09/2020.
//

#ifndef MOBILE_BANKING_APP_PERSONALAREAVIEW_H
#define MOBILE_BANKING_APP_PERSONALAREAVIEW_H

#include "../general_purpose_classes/InputManager.h"
#include "../reminder_classes/RemindersManagerView.h"
#include "../alert_classes/AlertsManagerView.h"
#include "../profile_classes/ProfileManagerView.h"
#include "../banking_accounts_classes/BankingAccountsManagerView.h"

class PersonalAreaView : public InputManager {
public:
    virtual ~PersonalAreaView() = default;
    void setClientName(const string& cname);

private:
    void display() override;
    bool isCorrectInput(const string &input) override;

    //attributes
    RemindersManagerView remindersManagerView;
    AlertsManagerView alertsManagerView;
    ProfileManagerView profileManagerView;
    BankingAccountsManagerView bankingAccountsManagerView;

    string clientName{"client"};

    //class constants
    static const string BANKING_ACCOUNTS;
    static const string PROFILE;
    static const string ALERTS;
    static const string REMINDERS;
    static const string LOGOUT;
};


#endif //MOBILE_BANKING_APP_PERSONALAREAVIEW_H
