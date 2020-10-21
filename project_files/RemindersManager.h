//
// Created by Rebecca on 30/09/2020.
//

#ifndef MOBILE_BANKING_APP_REMINDERSMANAGER_H
#define MOBILE_BANKING_APP_REMINDERSMANAGER_H

#include <map>
#include <string>

#include "Reminder.h"
#include "InputManager.h"
#include "Interface.h"

using namespace std;

class RemindersManager : public InputManager, public Interface {
public:
    void setClientName(const string &cname);

private:
    void pullFromServer();
    void updateServer() const;

    void display() override;

    bool isCorrectInput(const string &input) override;
    void tryAgain() override;
    void enableFailureRoutine() override;

    void displayAll();
    void displaySpecificReminder(const string& title);
    bool wantToSaveAsFile();

    void createReminder();
    void removeReminder(const string& title);

    static string insertTitle();

    map<string,Reminder> reminders;
    string clientName{"client"};

};

#endif //MOBILE_BANKING_APP_REMINDERSMANAGER_H
