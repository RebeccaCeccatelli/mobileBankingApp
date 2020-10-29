//
// Created by Rebecca on 30/09/2020.
//

#ifndef MOBILE_BANKING_APP_REMINDERSMANAGERVIEW_H
#define MOBILE_BANKING_APP_REMINDERSMANAGERVIEW_H

#include <string>

#include "../InputManager.h"
#include "RemindersManager.h"

using namespace std;

class RemindersManagerView : public InputManager {
public:
    virtual ~RemindersManagerView() = default;

    void setClientName(const string &cname);

private:
    void pullFromServer();
    void updateServer() const;

    void display() override;
    bool isCorrectInput(const string &input) override;

    static void showList(const vector<string>& selectedReminders);
    void showSpecificReminder(const string& title);

    void createReminder();
    void removeReminder(const string& title);

    bool wantToSaveAsFile();
    void saveAsFile(const string &title);

    static void displayReminder(const Reminder* reminder);
    static string insertTitle();
    static string insertText();

    //attribute
    RemindersManager remindersManager;
};

#endif //MOBILE_BANKING_APP_REMINDERSMANAGERVIEW_H
