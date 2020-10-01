//
// Created by Rebecca on 01/10/2020.
//

#ifndef MOBILE_BANKING_APP_ALERTSMANAGER_H
#define MOBILE_BANKING_APP_ALERTSMANAGER_H

#include <list>
#include <string>

#include "Alert.h"

using namespace std;

class AlertsManager {
public:
    void displayScreen();
    void setClientName(const string &cname);
    void createAlert();

private:

    void displayAll();
    void displayAlert(const string& topic);
    void displayNew();
    void setRead();

    list<Alert> alerts;
    string clientName;
};


#endif //MOBILE_BANKING_APP_ALERTSMANAGER_H
