//
// Created by Rebecca on 01/10/2020.
//

#ifndef MOBILE_BANKING_APP_ALERTSMANAGER_H
#define MOBILE_BANKING_APP_ALERTSMANAGER_H

#include <map>
#include <string>

#include "Alert.h"

#include "InputManager.h"

using namespace std;

class AlertsManager : public InputManager {
public:
    AlertsManager();

    virtual ~AlertsManager();

    void displayScreen();
    void setClientName(const string &cname);

private:
    void updateServer() const;
    bool isCorrectInput() override;

    void tryAgain() override;

    void enableFailureRoutine() override;
    void getDirectoryEntries();
private:
    void deserialize(const string& extractedPath);
    void displayAll();
    void displayGeneral();
    void displayPersonal();
    void displayUnread();
    void displayMessage(const string& object);
    bool wantToSaveAsFile();
    void saveAsFile(const string& object);

    map<string,Alert> alerts;
    string clientName;
};


#endif //MOBILE_BANKING_APP_ALERTSMANAGER_H
