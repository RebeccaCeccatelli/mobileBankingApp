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
    Reminder(string tit, string tex, string date, bool s);

    void display();

    const string& getTitle() const;
    void setSaved();
    bool isSaved() const;

    void serialize(const string &cname, string mainDirectory = "../my_files/") const;
    static pair<string, Reminder> deserialize(const string& extractedPath);

private:
    void setDate(char mode = 0, string date = "");
    string convertDateToString() const;
    tm convertDateToTm() const;

    void setUserTitle();
    void setUserText();

    string title{"unknown"};
    string text{"empty"};
    pair<tm,string> lastUpdate;
    bool saved{false};
};


#endif //MOBILE_BANKING_APP_REMINDER_H
