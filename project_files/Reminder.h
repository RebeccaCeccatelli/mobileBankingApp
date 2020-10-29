//
// Created by Rebecca on 30/09/2020.
//

#ifndef MOBILE_BANKING_APP_REMINDER_H
#define MOBILE_BANKING_APP_REMINDER_H

#include <string>
#include <ctime>

#include "DateSetter.h"

using namespace std;

class Reminder {
public:
    Reminder();
    Reminder(string tit, string tex, string date, bool s);

    void display();

    const string& getTitle() const;
    void setSaved();
    bool isSaved() const;

    void serialize(const string &cname, string mainDirectory = "../my_files/") const;
    static pair<string, Reminder> deserialize(const string& extractedPath);

private:
    void setUserTitle();
    void setUserText();

    string title{"unknown"};
    string text{"empty"};
    bool saved{false};
    DateSetter dateSetter;
};


#endif //MOBILE_BANKING_APP_REMINDER_H
