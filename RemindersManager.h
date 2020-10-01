//
// Created by Rebecca on 30/09/2020.
//

#ifndef MOBILE_BANKING_APP_REMINDERSMANAGER_H
#define MOBILE_BANKING_APP_REMINDERSMANAGER_H

#include <map>
#include <string>

#include "Reminder.h"
#include "InputManager.h"

using namespace std;

class RemindersManager : public InputManager {
public:
    void displayScreen();
    void setClientName(const string &cname);

private:
    void displayAllTitles();
    void displayReminder(const string& title);

    void createReminder();
    void removeReminder(const string& title);
    void deserialize(const string& fileName);

    static string insertTitle();
    //eventualmente remindereditor da aggiungere in un secondo momento
    //rivedere assetto "grafico" delle stampe a video TODO

    bool isCorrectInput() override;
    void tryAgain() override;
    void enableFailureRoutine() override;


private:
    map<string,Reminder> reminders;
    string clientName{"client"};
};

#endif //MOBILE_BANKING_APP_REMINDERSMANAGER_H
