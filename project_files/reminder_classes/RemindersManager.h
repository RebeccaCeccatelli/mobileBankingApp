//
// Created by rebecca on 10/29/20.
//

#ifndef MOBILE_BANKING_APP_REMINDERSMANAGER_H
#define MOBILE_BANKING_APP_REMINDERSMANAGER_H

#include <map>
#include <string>
#include <vector>

#include "Reminder.h"

using namespace std;

class RemindersManager {
public:
    void setClientName(const string& cname);

    void pullFromServer();
    void updateServer() const;


    void createReminder(const string& title, string text);
    bool removeReminder(const string& title);

    vector<string> returnAll() const;
    pair<bool,const Reminder*> returnSpecific(const string& title) const;

    bool saveAsFile(const string& title);

private:
    //attributes
    map<string,Reminder> reminders;
    string clientName{"client"};
};


#endif //MOBILE_BANKING_APP_REMINDERSMANAGER_H
