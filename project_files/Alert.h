//
// Created by Rebecca on 01/10/2020.
//

#ifndef MOBILE_BANKING_APP_ALERT_H
#define MOBILE_BANKING_APP_ALERT_H

#include <string>

#include "DateSetter.h"

using namespace std;

class Alert : public DateSetter {
public:
    Alert(string obj, string mex, bool r, bool pers, string date);

    void serialize(const string &cname, string mainDirectory = "../my_files/") const;
    static pair<string, Alert> deserialize(const string& extractedPath);

    void display();

    void setRead();
    bool isRead() const;
    bool isPersonal() const;

private:
    string object;
    string message;
    bool read;
    bool personal;
};

#endif //MOBILE_BANKING_APP_ALERT_H
