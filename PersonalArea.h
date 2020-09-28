//
// Created by Rebecca on 28/09/2020.
//

#ifndef MOBILE_BANKING_APP_PERSONALAREA_H
#define MOBILE_BANKING_APP_PERSONALAREA_H

#include "InputManager.h"

class PersonalArea : public InputManager {
public:
    void displayScreen();

private:
    bool isCorrectInput() override;
    void tryAgain() override;
    void enableFailureRoutine() override;


    /*BankingAccountsManager banking;
     * list<Reminder> reminders;
     * list<Alert> alerts;
     * ArchiveManager archiveManager;
     * BankServiceManager bsManager;
     * ProfileManager profileManager;*/
};


#endif //MOBILE_BANKING_APP_PERSONALAREA_H
