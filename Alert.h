//
// Created by Rebecca on 01/10/2020.
//

#ifndef MOBILE_BANKING_APP_ALERT_H
#define MOBILE_BANKING_APP_ALERT_H

#include <string>

using namespace std;

class Alert {
public:
    Alert(string obj, string mex, bool r, bool pers, string date);
    void serialize(const string &cname,const string& mainDirectory = "../my_files/") const;
    bool isRead() const;
    bool isPersonal() const;
    void setRead();
    void display();
    tm convertDateToTm() const;
private:
    string object;
    string message;
    pair<tm,string> arrivalDate;
    bool read{false};
    bool personal{false};

    void setDate(char mode = 0, const string &date = "");
};

#endif //MOBILE_BANKING_APP_ALERT_H
