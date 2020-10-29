//
// Created by rebecca on 10/28/20.
//

#ifndef MOBILE_BANKING_APP_ALERTSMANAGER_H
#define MOBILE_BANKING_APP_ALERTSMANAGER_H

#include <string>
#include <map>
#include <vector>

#include "Alert.h"

using namespace std;

class AlertsManager {
public:
    void setClientName(const string& cname);
    void pullFromServer();
    void updateServer() const;

    vector<string> returnAll() const;
    vector<string> returnGeneral() const;
    vector<string> returnPersonal() const;
    vector<string> returnUnread() const;
    pair<bool,const Alert*> returnSpecific(const string& object) const;

    bool saveAsFile(const string& object);
    bool setRead(const string& object);

    //method added to facilitate unit-testing
    void addAlert(const string& object, const string& message, bool r, bool pers, const string& date);

private:
    //attributes
    map<const string,Alert> alerts;
    string clientName;
};


#endif //MOBILE_BANKING_APP_ALERTSMANAGER_H
