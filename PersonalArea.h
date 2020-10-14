//
// Created by Rebecca on 28/09/2020.
//

#ifndef MOBILE_BANKING_APP_PERSONALAREA_H
#define MOBILE_BANKING_APP_PERSONALAREA_H

#include "InputManager.h"
#include "Interface.h"
#include "RemindersManager.h"
#include "AlertsManager.h"

class PersonalArea : public InputManager, public Interface {
public:
    void setClientName(const string& cname);

private:
    void display() override;

    bool isCorrectInput(string input) override;
    void tryAgain() override;
    void enableFailureRoutine() override;


    RemindersManager remindersManager;
    string clientName{"client"};
    AlertsManager alertsManager;
    /*BankingAccountsManager banking;

     * list<Alert> alerts;
     * ArchiveManager archiveManager;
     * BankServiceManager bsManager;
     * ProfileManager profileManager;*/
};


#endif //MOBILE_BANKING_APP_PERSONALAREA_H
