//
// Created by Rebecca on 01/10/2020.
//

#ifndef MOBILE_BANKING_APP_ALERTSMANAGERVIEW_H
#define MOBILE_BANKING_APP_ALERTSMANAGERVIEW_H

#include <string>

#include "../general_purpose_classes/InputManager.h"
#include "AlertsManager.h"

using namespace std;

class AlertsManagerView : public InputManager {
public:
    virtual ~AlertsManagerView() = default;

    void setClientName(const string &cname);

private:
    void pullFromServer();
    void updateServer() const;

    void display() override;
    bool isCorrectInput(const string &input) override;

    static void showList(const vector<string>& selectedAlerts);
    void showSpecificAlert(const string& object);

    //helper methods
    bool wantToSaveAsFile() const;
    void saveAsFile(const string& object);
    bool wantToSetAsRead() const;
    void setAsRead(const string& object);
    static void displayAlert(const Alert* alert);

    static string insertObject();

    //attribute
    AlertsManager alertsManager;
};



#endif //MOBILE_BANKING_APP_ALERTSMANAGERVIEW_H
