//
// Created by Rebecca on 30/09/2020.
//

#ifndef MOBILE_BANKING_APP_REMINDERSMANAGERVIEW_H
#define MOBILE_BANKING_APP_REMINDERSMANAGERVIEW_H

#include <string>

#include "../general_purpose_classes/InputManager.h"
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

    void createReminder();
    void removeReminder(const string& title);

    static void showList(const vector<string>& selectedReminders);
    void showSpecificReminder(const string& title);

    bool wantToSaveAsFile();
    void saveAsFile(const string &title);
    static void displayReminder(const Reminder* reminder);

    static string insertTitle();
    static string insertText();

    //attribute
    RemindersManager remindersManager;

    //class constants
    static const string DISPLAY_ALL;
    static const string DISPLAY_SPECIFIC;
    static const string CREATE;
    static const string REMOVE;
};

#endif //MOBILE_BANKING_APP_REMINDERSMANAGERVIEW_H
