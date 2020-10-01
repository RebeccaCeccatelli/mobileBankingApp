//
// Created by Rebecca on 30/09/2020.
//

#ifndef MOBILE_BANKING_APP_REMINDER_H
#define MOBILE_BANKING_APP_REMINDER_H

#include <string>
#include <ctime>

using namespace std;

class Reminder {
public:
    Reminder();
    Reminder(const string &tit, const string &tex, const string& date);

    void display();


    const string& getTitle() const;
    const string convertDateToString() const;
    void serialize(const string &cname) const;

private:
    void setUserTitle();
    void setUserText();
    void setLastUpdate(char mode = 0, const string& date = "");

    string title{"unknown"};
    string text{"empty"};
    pair<tm,string> lastUpdate;

    tm convertDateToTm() const;
};


#endif //MOBILE_BANKING_APP_REMINDER_H
