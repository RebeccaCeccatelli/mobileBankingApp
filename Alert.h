//
// Created by Rebecca on 01/10/2020.
//

#ifndef MOBILE_BANKING_APP_ALERT_H
#define MOBILE_BANKING_APP_ALERT_H

#include <string>

using namespace std;

class Alert {
public:
    Alert(string obj, string mex, bool pers = false);
    void serialize(const string &cname);
    void convertDatefromTmtoString();
    bool isRead() const;
    bool isPersonal() const;
    void setRead();
    void display();
private:
    string object;
    string message;
    pair<tm,char[80]> arrivalDate;
    bool read{false}, personal;

    void setDate();
};

#endif //MOBILE_BANKING_APP_ALERT_H
