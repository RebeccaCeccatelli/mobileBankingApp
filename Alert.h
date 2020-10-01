//
// Created by Rebecca on 01/10/2020.
//

#ifndef MOBILE_BANKING_APP_ALERT_H
#define MOBILE_BANKING_APP_ALERT_H

#include <string>

using namespace std;

class Alert {
public:
    Alert();
    void serialize(const string &cname);
    void convertDatefromTmtoString();
private:
    string title;
    string message;
    pair<char[80],tm> arrivalDate;
    bool read{false};

    void setTitle();
    void setDate();
    void setText();
};

#endif //MOBILE_BANKING_APP_ALERT_H
