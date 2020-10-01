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
    Reminder(const string &tit, const string &tex);
    void display();

    void setTitle();
    void setText();
    void setCreationDate();

    const string& getTitle() const;
    const string& getText() const;
    const string getCreationDate() const;
    void serialize(const string &cname) const;

private:
    string title{"unknown"};
    string text{"empty"};
    tm lastUpdate{0, 0, 0, 1, 0, 120,
                  1, 0, -1};  // default : lunedì 1 gennaio 2020, 0:00:00
};


#endif //MOBILE_BANKING_APP_REMINDER_H
