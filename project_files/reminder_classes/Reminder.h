//
// Created by Rebecca on 30/09/2020.
//

#ifndef MOBILE_BANKING_APP_REMINDER_H
#define MOBILE_BANKING_APP_REMINDER_H

#include <string>
#include <ctime>

#include "../general_purpose_classes/DateSetter.h"

using namespace std;

class Reminder {
    friend class RemindersManagerView;
public:
    Reminder(const string &tit, string tex);
    Reminder(string tit, string tex, string date, bool s);

    void serialize(const string &cname, string mainDirectory = "../my_files/") const;
    static pair<string, Reminder> deserialize(const string& extractedPath);

    void setSaved();
    bool isSaved() const;

private:
    //attributes
    string title{"unknown"};
    string text{"empty"};
    bool saved{false};

    DateSetter dateSetter;
};


#endif //MOBILE_BANKING_APP_REMINDER_H
